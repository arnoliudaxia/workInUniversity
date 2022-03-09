#include <stdio.h>
#include <string.h>

int max(int a, int b)
{
    return a > b ? a : b;
}
int min(int a, int b)
{
    return a > b ? b : a;
}
char *str1 = "12344632165";
char *str2 = "123111321618";
int m = 5, n = 4;

// 现在已经找到两个字符串在某个位置有一样的字符，现在就看后面的字符一不一样
int matchString(int s, int t)
{
    int result = 1;
    int largestRe = min(m - s - 1, n - t - 1);

    int i=1;
    char c1,c2;
    ahwqkljelqw:
    c1=str1[s + i];
    c2= str2[t + i];
        if (c1 !=c2)
        goto ENLNSLK;
        result++;
        i++;
        if(i<=largestRe)goto ahwqkljelqw;
    ENLNSLK:
    return result;
}
// 这个函数在longstring中寻找s的匹配项
int searchForOne(int s)
{
    int result = 0;
    char finder = str1[s];
    int i = 0;
    char another;
forasdwqewq:
    another=str2[i];
    if (finder !=another )
        goto ifaijewjeioq;

    result = max(matchString(s, i), result);

ifaijewjeioq:
    i++;
    if (i < n)
        goto forasdwqewq;

    return result;
}
int main()
{
    m=strlen(str1);
    n=strlen(str2);
    int result = 0;
    for (int i = 0; i < m; i++)
    {
        result = max(result, searchForOne(i));
    }
    printf("%d\n", result);
    return 0;
}