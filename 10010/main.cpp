#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX 50

int main(void)
{
    freopen("input.txt","r",stdin);
    int cases;
    char wordmatrix[MAX][MAX]={""};/**�ַ�����**/
    char wordlist[MAX+5][MAX];
    scanf("%d",&cases);/**�ܹ��ж���������**/
    for(int useless=1;useless<=cases;useless++)/**��������**/
    {
        int this_word_find=0;
        int find=0;
        int m,n;
        scanf("%d%d",&m,&n);
        for(int M=1;M<=m;M++)/**������ĸ����**/
            scanf("%s",wordmatrix[M]);
        for(int M=1;M<=m;M++)
            for(int N=0;wordmatrix[M][N]!='\0';N++)
                if(wordmatrix[M][N]<='Z' && wordmatrix[M][N]>='A') wordmatrix[M][N]+=32;
        /**����ĸ�������ͳһСдת������**/
        int k;
        scanf("%d",&k);
        for(int counter=1;counter<=k;counter++)/**���뵥���ֵ�**/
            scanf("%s",wordlist[counter]);

        for(int r=1;r<=k;r++)
            for (int qqw=0;wordlist[r][qqw]!='\0';qqw++)
                if(wordlist[r][qqw]<='Z' && wordlist[r][qqw]>='A') wordlist[r][qqw]+=32;
        /**ͬ�����ֵ�Ĵ�Сдͳһ**/
        /**�����ǹؼ�����:�ж�ģ��**/
        for(int oo=1;oo<=k;oo++)/**һ������һ���ж�ģ��**/
        {
            //printf("\n");
            this_word_find=0;/**������ʵ��ҵ���־��ʼ��Ϊ0 ��ʾû�ҵ� ��Ϊ1 ��ʾ�ҵ�**/
            for(int M=1;M<=m;M++)
            {
                for(int N=0;wordmatrix[M][N]!='\0';N++)
                {
                    if(wordlist[oo][0]!=wordmatrix[M][N]) continue;//�����һ����ĸ�Ͳ�ƥ�� ��ô �������λ�� ������һ�ж�
                    int len=strlen(wordlist[oo]);//��ȡ�ַ����ĳ���
                    /**��ʼ����**/
                    //find=1;//���ұ�־find��ʼ��Ϊ1
                    /**���հ˸��������β��� ���в��������˳�**/
                    //printf("\n");
                    for(int finding=0;finding<=len-1;finding++)
                        if(wordmatrix[M][N+finding]!=wordlist[oo][finding]) {find=0;break;} else if(finding==len-1) find=1;
                    //printf("right %d",find);
                    for(int finding=0;finding<=len-1 && !find ;finding++)
                        if(wordmatrix[M][N-finding]!=wordlist[oo][finding]){find=0;break;} else if(finding==len-1) find=1;
                    //printf("left %d",find);
                    for(int finding=0;finding<=len-1 && !find ;finding++)
                        if(wordmatrix[M+finding][N+finding]!=wordlist[oo][finding]) {find=0;break;} else if(finding==len-1) find=1;
                    for(int finding=0;finding<=len-1 && !find ;finding++)
                        if(wordmatrix[M-finding][N-finding]!=wordlist[oo][finding]) {find=0;break;} else if(finding==len-1) find=1;
                    for(int finding=0;finding<=len-1 && !find ;finding++)
                        if(wordmatrix[M+finding][N]!=wordlist[oo][finding]) {find=0;break;} else if(finding==len-1) find=1;
                    for(int finding=0;finding<=len-1 && !find ;finding++)
                        if(wordmatrix[M-finding][N]!=wordlist[oo][finding]) {find=0;break;} else if(finding==len-1) find=1;
                    for(int finding=0;finding<=len-1 && !find ;finding++)
                        if(wordmatrix[M+finding][N-finding]!=wordlist[oo][finding]) {find=0;break;} else if(finding==len-1) find=1;
                    for(int finding=0;finding<=len-1 && !find ;finding++)
                        if(wordmatrix[M-finding][N+finding]!=wordlist[oo][finding]) {find=0;break;} else if(finding==len-1) find=1;
                    if(find==1)
                    {
                        printf("%d %d",M,N+1);
                        if(oo<k) printf("\n");
                        if(oo==k) printf("\n");
                        this_word_find=1;
                        break;
                    }
                    if(this_word_find==1) break;
                }
                if(this_word_find==1) break;/**���漸�д����ʾ ���ҵ��˵���һ�� �Ͳ��������������**/
            }
        }
        if(useless<cases) printf("\n");
    }
}

/**Accepted 2013-12-28 02:46:57**/
