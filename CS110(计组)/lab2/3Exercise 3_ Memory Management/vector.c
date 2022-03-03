/* Include the system headers we need */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* Include our header */
#include "vector.h"

/* Define what our struct is */
struct vector_t
{
    size_t size;
    int *data;
};

/* Utility function to handle allocation failures. In this
   case we print a message and exit. */
static void allocation_failed()
{
    fprintf(stderr, "Out of memory.\n");
    exit(1);
}

/* Bad example of how to create a new vector */
vector_t *bad_vector_new()
{ //创建的vector只能保证可以存一个int，扩容的时候不能保证之后的内存空间是空的
    /* Create the vector and a pointer to it */
    vector_t *retval, v;
    retval = &v;

    /* Initialize attributes */
    retval->size = 1;
    retval->data = malloc(sizeof(int));
    if (retval->data == NULL)
    {
        allocation_failed();
    }

    retval->data[0] = 0;
    return retval;
}

/* Another suboptimal way of creating a vector */
vector_t also_bad_vector_new()
{ //除了上述问题之外，这里的v只是一个局部变量，在跳出的时候就无法保证能存活
    /* Create the vector */
    vector_t v;

    /* Initialize attributes */
    v.size = 1;
    v.data = malloc(sizeof(int));
    if (v.data == NULL)
    {
        allocation_failed();
    }
    v.data[0] = 0;
    return v;
}

/* Create a new vector with a size (length) of 1
   and set its single component to zero... the
   RIGHT WAY */
vector_t *vector_new()
{
    /* Declare what this function will return */
    vector_t *retval;

    /* First, we need to allocate memory on the heap for the struct */
    retval = (vector_t *)malloc(sizeof(vector_t));

    /* Check our return value to make sure we got memory */
    if (!retval)
    {
        allocation_failed();
    }

    //一开始默认预留16个，往后每增一位就扩容
    retval->size = 16;
    retval->data = (int *)calloc(16, sizeof(int));

    /* Check the data attribute of our vector to make sure we got memory */
    if (!(*(retval->data) == 0 && *(retval->data + 9) == 0))
    {
        free(retval); // Why is this line necessary?
        allocation_failed();
    }

    /* and return... */
    return retval;
}

/* Return the value at the specified location/component "loc" of the vector */
int vector_get(vector_t *v, size_t loc)
{

    /* If we are passed a NULL pointer for our vector, complain about it and exit. */
    if (v == NULL)
    {
        fprintf(stderr, "vector_get: passed a NULL vector.\n");
        abort();
    }

    /* If the requested location is higher than we have allocated, return 0.
     * Otherwise, return what is in the passed location.
     */
    if (loc <= v->size - 1)
    {
        return *(v->data + loc);
    }
    else
    {
        return 0;
    }
}

/* Free up the memory allocated for the passed vector.
   Remember, you need to free up ALL the memory that was allocated. */
void vector_delete(vector_t *v)
{
    /* YOUR SOLUTION HERE */
    free(v->data);
    free(v);
}

inline static int nextSize(int size)
{
    for (int i = 16;; i *= 2)
    {
        if (size >= i && size <= i * 2)
            return i * 2;
    }
}
/* Set a value in the vector. If the extra memory allocation fails, call
   allocation_failed(). */
void vector_set(vector_t *v, size_t loc, int value)
{

    if (loc >= v->size) //超过索引
    {
        int ns = nextSize(loc);
        int *newaddress = (int *)calloc(ns,sizeof(int));
        if (!newaddress)
        {
            vector_delete(v);
            allocation_failed();
        }
        for (size_t i = 0; i < v->size; i++)
        {
            newaddress[i] = v->data[i];
        }
        free(v->data);

        // v->data=(int*)realloc(v->data,ns);
        //    memset(v->data+(v->size)+1,0,ns-(v->size));
        v->size = ns;
        v->data = newaddress;
    }
    v->data[loc] = value;
}