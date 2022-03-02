x86 : main.c
	gcc	-Wpedantic -Wall -Wextra -Werror -std=c89 -o main32  main.c -m32
	./main32

x86_64 : main.c
	gcc	-Wpedantic -Wall -Wextra -Werror -std=c89 -o main64  main.c -m64
	./main64

clean : 
	rm -f  main32 mian64
