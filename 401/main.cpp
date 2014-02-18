#include<stdio.h>
#include<string.h>

#define MAX 30
#define MAXN 100000

char mirror[25]= "AEHIJLMOSTUVWXYZ12358";
char _mirror[25]="A3HILJMO2TUVWXY51SEZ8";       //���������ַ���
//=======Function Prototype======
int judge_mirror(char *s);
int judge_palindrome(char *s);
//===============================
int main(void)
{
    //freopen("input.txt","r",stdin);
    //freopen("outputOK.txt","w",stdout);
    char s[MAX];
    int j_mirror,j_palindrome;
    while(scanf("%s",s)!=EOF)
    {
        j_mirror=judge_mirror(s);//Judge if mirror
        j_palindrome=judge_palindrome(s);//Judge if Palindrome
        printf("%s",s);
        switch(j_mirror+j_palindrome)//Output Result
        {
        case 0:
            printf(" -- is not a palindrome.\n\n");
            break;
        case 1:
            printf(" -- is a regular palindrome.\n\n");
            break;
        case 2:
            printf(" -- is a mirrored string.\n\n");
            break;
        case 3:
            printf(" -- is a mirrored palindrome.\n\n");
            break;
        }
    }
    return 0;
}
int judge_mirror(char *s)
{
    char *ini=s;
    int len=strlen(mirror);
    while(*(++s)!='\0')
    {
        if(strchr(mirror,*s)==NULL) return 0;               //����е��ַ��������Ǿ����ַ��е��κ�һ�� ��ô����Ǿ���
    }

                                                            //�������ַ����Ǿ����ַ��е��ַ� ��ô��ʼ�Ƚ���һ��
    s--;
    if(strlen(s)==1 && strchr(mirror,*s)==NULL) return 0;   //����������� ֻ��һ���ַ������                                               //s���ָ��\0��Ҫ��s����һ����λ

    while(ini<=s)                                           //����ָ��һ��ɨ�����ַ��� һ���Ӻ�ɨ һ����ͷɨ
    {
        for(int oo=0;oo<len;oo++)
        {
             if((*ini==mirror[oo] && *s==_mirror[oo]) || *ini!=mirror[oo]) continue;
             return 0;
        }
        ini++;
        s--;
    }
    return 2;                                   //Return 2 Indicates it's a mirror string
}

int judge_palindrome(char *s)
{
    char *ini=s;
    while(*(s++));                              //��ָ���ƶ����ַ���ĩβ��һ���ַ�
    s-=2;                                       //�ƶ���\0ǰ
    while(ini<=s)
    {
        if(*ini!=*s) return 0;
        ini++;
        s--;
    }
    return 1;                                   //Return 1 Indicates it's a palindrome
}

/**���鿪�Ĳ����� �Ժ���ŵ� ��������ֱ������ͱ����� ��ʽ���⻹�Ǻ���**/
