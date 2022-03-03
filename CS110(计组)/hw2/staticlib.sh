gcc -c *.c
ar -crv libringbuffer.a ringbuffer.o
# gcc -o staticringbuffer test.c libringbuffer.a
ld -e main -o staticringbuffer test.o -L . -lringbuffer -lc
