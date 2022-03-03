#ifndef __RING_BUFFER_H
#define __RING_BUFFER_H
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "ringbuffer.h"

/* To use boolean expressions */
typedef int bool;
#define true (1)
#define false (0)

/* Initial size of the buffer */
#define RING_BUFFER_INIT_SIZE 8

/* You should grow buffer size to RING_BUFFER_GROW_FACTOR1 * capacity, when current capacity < 1024
   And RING_BUFFER_GROW_FACTOR2 * capacity, when current capacity >= 1024 */
#define RING_BUFFER_GROW_FACTOR1 2
#define RING_BUFFER_GROW_FACTOR2 1.5

/* The ring_buffer structure */
typedef struct ring_buffer_
{
   /*the structure*/
   size_t capacity;
   size_t read_pos;
   size_t write_pos;
   int *content;
} ring_buffer; /*convinece*/

/* A function pointer for mapping operations */
typedef int (*map_func)(int);

/* Create a new ring buffer. You should allocate memory for its content,
   initialize the read_pos, write_pos and capacity properly.
   And finally return a pointer to the new ring buffer. */
ring_buffer *ring_buffer_new()
{
   ring_buffer *rb = (ring_buffer *)malloc(sizeof(ring_buffer));
   /* return NULL;*/
   rb->capacity = RING_BUFFER_INIT_SIZE;
   /* new a ring_buffer and init its properties
    */
   rb->content = (int *)malloc(sizeof(int) * RING_BUFFER_INIT_SIZE);
   rb->read_pos = 0;
   rb->write_pos = 0;
   return rb;
}

/*smart increase index*/
static void posIncreaseByone(size_t capacity, size_t *pos)
{
   if (++(*pos) >= capacity)
      *pos = 0;
}
/* Destroy the given ring buffer, free all resources you've allocated.
   Finally you should set the buffer pointer to NULL, that is why we pass
   ring_buffer** as parameter, instead of ring_buffer*. */
void ring_buffer_destroy(ring_buffer **buffer)
{
   if(buffer)
   {
   ring_buffer *target = *buffer;
   free(target->content);
   /* Destory everything
    */
   free(target);
   *buffer = NULL;
   }
}

/* Returns true if the given ring buffer is empty, false otherwise */
bool ring_buffer_is_empty(const ring_buffer *buffer)
{
   if(!buffer)return true;
   /* always keep one slot empty, then write==read means empty*/
   return buffer->write_pos == buffer->read_pos ? 1 : 0;
}
bool ring_buffer_is_full(const ring_buffer *buffer)
{

   size_t temp;
   if(!buffer)return false;/*check empty*/
   temp = buffer->write_pos;
   /* always keep one slot empty, then write==read means empty*/
   posIncreaseByone(buffer->capacity, &temp);
   /* always keep one slot empty, then write==read means empty*/
   return temp == buffer->read_pos ? 1 : 0;
}

/* Read an element from the ring buffer (i.e., the dequeue operation), *data records
   the element popped. returns true if the operation succeeded, false otherwise. */
bool ring_buffer_read(ring_buffer *buffer, int *data)
{
   int result;
   if(!data||!buffer)return false;
   /* assert(buffer&&data);*/
   if (ring_buffer_is_empty(buffer)) /* read is meaningless if it's empty*/
      return false;
   result = (buffer->content[buffer->read_pos]);
   posIncreaseByone(buffer->capacity, &(buffer->read_pos)); /* update the read pointer*/
   *data = result;
   return true;
}

static void expand(ring_buffer *buffer)
{
   /*the declartion must be top*/
   int sizeb, *newaddress;
   size_t i;

   sizeb = buffer->capacity;
   /*request a new var

   */
   sizeb = sizeb < 1024 ? sizeb * RING_BUFFER_GROW_FACTOR1 : sizeb * RING_BUFFER_GROW_FACTOR2;
   newaddress = (int *)calloc(sizeb, sizeof(int));

   for (i = 0; i < buffer->capacity; i++)
   {
      int data;
      /*copy value*/
      if (ring_buffer_read(buffer, &data))
         newaddress[i] = data;
      else
      {
         /*stop copying*/
         buffer->write_pos = i;
         break;
      }
   }
   /*reinit buffer*/
   free(buffer->content);
   buffer->content = newaddress;
   buffer->read_pos = 0;
   buffer->capacity = sizeb;
}
/* Write an element which value is `data` to the ring buffer (i.e., the enqueue operation),
   returns true if the operation succeeded, false otherwise. Note that when the buffer is
   full, grow its size to make sure the element can be write successfully. The detailed
   requirements of size growth are in the homework description. */
bool ring_buffer_write(ring_buffer *buffer, const int data)
{
   if(!buffer)return false;
   if (ring_buffer_is_full(buffer))
      /*chech whether is full*/
      expand(buffer);
   buffer->content[buffer->write_pos] = data;
   posIncreaseByone(buffer->capacity, &(buffer->write_pos));
   /*remeber to increase the index*/
   return true;
}

static size_t elementNum(ring_buffer *buffer)
{
   int spaceused = 0;
   if (buffer->write_pos >= buffer->read_pos)
   {
      /* spaceused = write-read+1*/
      spaceused = (buffer->write_pos - buffer->read_pos);
   }
   else
   {
      /* spaceleft=read-write-1*/
      spaceused = buffer->capacity - (buffer->read_pos - buffer->write_pos);
   }
   return spaceused;
}

/* Read "rdsize" elements from the ring buffer, and fill them to "data".
   Notice that you should only return true when this operation succeeds.
   If there are not enough elements in the buffer, just DO NOTHING and
   return false. DO NOT modify the ring buffer and data for such cases. */
bool ring_buffer_read_multi(ring_buffer *buffer, size_t rdsize, int *data)
{
   size_t i;
   if(!(rdsize>0&&data))return false;
   if (elementNum(buffer)< rdsize)/*No enough elements*/
      return false;
   for (i = 0; i < rdsize; i++)
   {
      /*read one by one*/
      int datar;
      ring_buffer_read(buffer, &datar);
      data[i] = datar;
   }
   return true;
}

/* Write "wrtsize" elements to the ring buffer. The values to write are
   provided in "data". Returns true if succeeds, false otherwise. Don't
   forget to grow your buffer size properly. */
bool ring_buffer_write_multi(ring_buffer *buffer, size_t wrtsize, const int *data)
{
   size_t i;
   if(!(wrtsize>0&&data))return false;

   if (!buffer || !data)
   {
   /* always keep one slot empty, then write==read means empty*/
      return false;
   }
   /* check the vaildness*/
   for (i = 0; i < wrtsize; i++)
   {
      ring_buffer_write(buffer, data[i]);
   }
   return true;
}

/* For every element in the ring buffer, apply "func" to it. For example,
   Your buffer currently contains 3 elements 1, 2, 4. If the map function is to
   "add five", then their values should be 6, 7, 9 after calling this function. */
bool ring_buffer_map(ring_buffer *buffer, map_func func)
{
   /*just put func on every element*/
   size_t i;
   if(!buffer)return false;
   for (i = 0; i < buffer->capacity; i++)
   {
      buffer->content[i] = func(buffer->content[i]);
   }
   /*success flag*/
   return true;
}

#endif
