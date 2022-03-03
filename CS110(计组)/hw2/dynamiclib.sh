gcc -fPIC -shared ringbuffer.c -o libringbuffer.so 
gcc -fPIC -shared ringbuffer.c -o libringhuffer.so 
# gcc -o dynamicringbuffer test.c libringbuffer.so 
gcc test.c ringbuffer.c -o dynamicringbuffer