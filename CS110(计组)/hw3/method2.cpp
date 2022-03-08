#include <stdio.h>
#include <string.h>
#include <malloc.h>

int max(int a, int b)
{
    return a > b ? a : b;
}
int min(int a, int b)
{
    return a > b ? b : a;
}


//// 现在已经找到两个字符串在某个位置有一样的字符，现在就看后面的字符一不一样
//int matchString(int s, int t)
//{
//    int result = 1;
//    int largestRe = min(a4 - s - 1, a5 - t - 1);
//
//    int i = 1;
//    char c1, c2;
//ahwqkljelqw:
//    c1 = a2[s + i];
//    c2 = a3[t + i];
//    if (c1 != c2)
//        goto ENLNSLK;
//    result++;
//    i++;
//    if (i <= largestRe)goto ahwqkljelqw;
//ENLNSLK:
//    return result;
//}
//// 这个函数在longstring中寻找s的匹配项
//int searchForOne(int s)
//{
//    int result = 0;
//    char finder = a2[s];
//    int i = 0;
//    char another;
//forasdwqewq:
//    another = a3[i];
//    if (finder != another)
//        goto ifaijewjeioq;
//
//    result = max(matchString(s, i), result);
//
//ifaijewjeioq:
//    i++;
//    if (i < a5)
//        goto forasdwqewq;
//
//    return result;
//}
char loadString(const char* str, int index)
{
    return str[index];
}
int main() 
{
    const char* s7 = "66655589220955064123197";
    const char* s8 = "9721127629403007399121698442453724";
    int a4 = 5, a5 = 4;
    a4 = strlen(s7);
    a5 = strlen(s8);
    int s1 = 0;
    //int* s4 = (int*)calloc(a4 + 1, sizeof(int));
    //int* s5 = (int*)calloc(a5 + 1, sizeof(int));
    int s4[200], s5[200];


    int s9 = 1;
    WJOIJE:
        int s10 = 1;
        char t2 = loadString(s7, s9 - 1);
    SHDIOWHOI:
        char t3 = loadString(s8, s10 - 1);
        if (t2 != t3)goto SJDIOW;

        *(s5+s10) = *(s4+s10 - 1) + 1;
        s1 = max(s5[s10], s1);
    SJDIOW:

        s10++;
        if (s10 < a5 + 1)goto SHDIOWHOI;

        s10 = 0;
    SJIWJIO:
            *(s4+s10) = *(s5+s10);
            *(s5+s10) = 0;
        
        s10++;
        if (s10 < a5 + 1)goto SJIWJIO;
    
    s9++;
    if (s9 < a4 + 1)goto WJOIJE;

    printf("%d\n", s1);

    return 0;
}