#define LOCAL
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 1010

char a[MAX][40];            //�û������ִ�
char b[MAX][40];            //�û�
int cmp_string(const void *a,const void *b)
{
    char *a_=(char*) a;
    char *b_=(char*) b;
    return strcmp(a,b);
}

int cmp_char(const void *a,const void *b)
{
    char *a_=(char*) a;
    char *b_=(char*) b;
    return *a_-*b_;
}

int main(void)
{
    #ifdef LOCAL
        freopen("156.in","r",stdin);
    #endif // LOCAL
    while scanf("%s",)
}
