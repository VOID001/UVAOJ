#include<stdio.h>
#include<string.h>

#define MAX 10000
#define J_ALPHA (ch[oo]<='Z' && ch[oo]>='A') || (ch[oo]<='Z' && ch[oo]>='A')
char ch[100];

int main(void)
{
    int pre=0;/**ǰһ�ַ��ı�־ 1��ĸ 0 ����ĸ**/
    int now=0;/**��ǰ�ַ��ı�־ 1��ĸ 0 ����ĸ**/
    while(gets(ch))
    {
        int word=0;
        pre=0;
        now=0;
        for(int oo=0;ch[oo]!='\0';oo++)
        {
            pre=now;//ǰһ�����now�ǵ�ǰ��pre
            if((ch[oo]<='Z' && ch[oo]>='A') || (ch[oo]<='z' && ch[oo]>='a')) now=1; else now=0;
            if(pre==0 && now==1) word++;
        }
        printf("%d\n",word);
    }
}
/**Accepted 2013-12-27 11:49:51**/
