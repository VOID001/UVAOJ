//#define LOCAL
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<limits.h>

#define MAX 100000

int cmp_bign(char *s);
char *remove_zero(char *s);

int big1[MAX],big2[MAX],res[MAX];
char s1[MAX],op[2],s2[MAX],s3[MAX];

int main(void)
{
    #ifdef LOCAL
        freopen("465.in","r",stdin);
        freopen("465.out","w",stdout);
    #endif // LOCAL

    int addon,tmp,maxn;
    while(scanf("%s%s%s",s1,op,s2)!=EOF)
    {
        memset(big1,0,sizeof(big1));
        memset(big2,0,sizeof(big2));
        memset(res,0,sizeof(res));
        char *pt1=s1;
        char *pt2=s2;
        pt1=remove_zero(s1);
        pt2=remove_zero(s2);
        int len1=strlen(s1);
        int len2=strlen(s2);
        for(int i=0;i<len1;i++) big1[i]=s1[len1-i-1]-'0';
        for(int i=0;i<len2;i++) big2[i]=s2[len2-i-1]-'0';
        switch(op[0])
        {
        case '+':
            maxn=len1>len2 ? len1:len2;
            addon=0;
            for(int i=0;i<MAX;i++)
            {
                tmp=big1[i]+big2[i]+addon;
                res[i]=tmp%10;
                addon=tmp/10;
            }
            break;
        case '*':
            for (int j=0;j<len2;j++)
            {
                addon=0;
                for(int i=0;i<=len1;i++)
                {
                    tmp=res[i+j]+big2[j]*big1[i]+addon;
                    res[i+j]=tmp%10;
                    addon=tmp/10;
                }
            }
            break;
        }
        int ok=0;
        char *pt=s3;
        for(int i=MAX-1;i>=0;i--)
        {
            if(res[i]) ok=1;
            if(ok) sprintf(pt++,"%d",res[i]);
        }
        if(!ok) sprintf(pt++,"0");
        *pt='\0';
        if(!strcmp(pt1,"")) strcpy(pt1,"0");
        if(!strcmp(pt2,"")) strcpy(pt2,"0");
        printf("%s %s %s\n",pt1,op,pt2);
        if(cmp_bign(pt1)==1) printf("first number too big\n");
        if(cmp_bign(pt2)==1) printf("second number too big\n");
        if(cmp_bign(s3)==1) printf("result too big\n");
    }
}

int cmp_bign(char *s)
{
    char bigs[50];
    sprintf(bigs,"%d",INT_MAX);
    int len=strlen(bigs);
    //ÅÐ¶Ï´óÐ¡
    if(!strcmp(s,bigs)) return 0;
    else if(strlen(s)>len) return 1;
    else if(strlen(s)<len) return -1;
    else if(strlen(s)==len)
    {
        for(int i=0;i<len;i++)
            if(s[i]>bigs[i]) return 1;
        return -1;
    }
}

char *remove_zero(char *s)                          //去掉前导零
{
    while((*(s++) - '0')==0) ;
    return s-1;
}
