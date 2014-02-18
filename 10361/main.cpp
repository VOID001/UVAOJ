#include<stdio.h>
#include<string.h>
#define MAX 1000

char get1[MAX];
char get2[MAX];
char get3[MAX];
char get4[MAX];

//Function Prototype
void auto_get(char *s);
char *auto_copy(char *s);
char *auto_copy2(char *s);
//END OF PROTOTYPE
int main(void)
{
    //freopen("input.txt","r",stdin);
    char s1[MAX]="";
    char s2[MAX]="";
    long long  cases;
    scanf("%lld",&cases);
    for(long long i=1;i<=cases;i++)
    {
        memset(s1,0,sizeof(s1));
        memset(s2,0,sizeof(s2));
        memset(get1,0,sizeof(get1));
        memset(get2,0,sizeof(get2));
        memset(get3,0,sizeof(get3));
        memset(get4,0,sizeof(get4));
        if(i==1) getchar();                              //scanf �����س� ���Ҹ��ϵ�gets�Ͱ��Ǹ��س��������� ��� Ҫ��getchar�ѻس�������
        gets(s1);
        gets(s2);                               //�����������
        auto_get(s1);                           //auto_get ��� s2 s3 s4 s5=get1 get2 get3 get4
        //printf("%s\n%s\n%s\n%s",get1,get2,get3,get4);DEBUG
        char *res=auto_copy(s1);
        printf("%s\n",res);
        res=auto_copy2(s2);
        printf("%s\n",res);
    }
}

void auto_get(char *s)
{
    int len;
    len=strchr(s,'>')-strchr(s,'<');              //����ֶγ��ȼ�<���һ���ַ���ַ ������ˣ�����
    if(len==1) get1[0]='\0';                      //�����������  �ַ�Ϊ��
    else
    {
        for(int i=1;i<len;i++)
        {
            get1[i-1]=*(strchr(s,'<')+i);
        }
        get1[len-1]='\0';
    }
    *strchr(s,'<')='.';
    len=strchr(s,'<')-strchr(s,'>');              //����ǵڶ����ִ���
    if(len==1) get2[0]='\0';                      //�����������  �ַ�Ϊ��
    else
    {
        for(int i=1;i<len;i++)
        {
            get2[i-1]=*(strchr(s,'>')+i);
        }
        get2[len-1]='\0';
    }
    *strchr(s,'>')='#';                           //Ϊ����strchr���ҵ���һ��<>�� ��Ҫ���Ѿ��ҵ���ȥ��
    len=strchr(s,'>')-strchr(s,'<');              //����ǵڶ����ִ���
    if(len==1) get3[0]='\0';                      //�����������  �ַ�Ϊ��
    else
    {
        for(int i=1;i<len;i++)
        {
            get3[i-1]=*(strchr(s,'<')+i);
        }
        get3[len-1]='\0';
    }
    *strchr(s,'<')='#';
    len=strchr(s,'\0')- strchr(s,'>');             //����ǵڶ����ִ���
    if(len==1) get4[0]='\0';                      //�����������  �ַ�Ϊ��
    else
    {
        for(int i=1;i<len;i++)
        {
            get4[i-1]=*(strchr(s,'>')+i);
        }
        get4[len-1]='\0';
    }
    return ;
}

char *auto_copy(char *s)
{
    char *ini=s;
    char src[MAX]="";
    strcat(src,get1);
    strcat(src,get2);
    strcat(src,get3);
    strcat(src,get4);
    strcpy(strchr(s,'.'),src);
    return ini;
}

char *auto_copy2(char *s)
{
    char *ini=s;
    char src[MAX]="";
    strcat(src,get3);
    strcat(src,get2);
    strcat(src,get1);
    strcat(src,get4);
    strcpy(strchr(s,'.'),src);
    return ini;
}
