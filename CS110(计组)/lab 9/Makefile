CC=gcc
CFLAGS= -O0 -std=gnu99

all: sum
sum: sum.c
	$(CC) $(CFLAGS) -o sum sum.c
	./sum

sumO2:
	$(CC) -O2 -std=gnu99 -o sum sum.c
	./sum

sseTest.s : sseTest.c
	$(CC) -S sseTest.c

clean:
	rm -rf sum
runsum:
	./sum