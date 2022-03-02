#include <stdio.h>
#include <time.h>
#define printSize(varible) (printf("Size of %s: %d\n", #varible, (int)sizeof(varible)))
int main()
{
    printSize(char);
    printSize(short);
    printSize(short int);
    printSize(int);
    printSize(long int);
    printSize(unsigned int);
    printSize(void *);
    printSize(size_t);
    printSize(float);
    printSize(double);
    printSize(__int8_t);
    printSize(__int16_t);
    printSize(__int32_t);
    printSize(__int64_t);
    printSize(time_t);
    printSize(clock_t);
    printSize(struct tm);
    printSize(NULL);

    return 0;
}
