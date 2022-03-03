CC=gcc
CFLAGS=-Wpedantic -Wall -Wextra -Werror -std=c89

all: main

main: main.c ringbuffer.c ringbuffer.h
	${CC} ${CFLAGS} ringbuffer.c main.c -o main
	./main

memcheck: main
	valgrind --tool=memcheck --leak-check=full ./main

submit:
	tar -cvf hw2.tar ringbuffer.c dynamiclib.sh staticlib.sh

clean:
	rm -f ./main
	rm -f ./*.o

.PHONY: clean