#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX 150

char s[MAX];

//Function Prototype
void build_maze();
//******************

int main(void)
{
    //Read��in INPUT
    //freopen("input.txt","r",stdin);
    while(gets(s)!=NULL)
    {
        build_maze();
        printf("\n") ;                  //Build the Maze
    }
    return 0;
}

void build_maze()
{
    int times=0;char ch;                  //�ظ����� ���ظ��ַ�
    int len=0;                          //ÿ������֮��ľ��� len ��ʼ��Ϊ0
    //char *pt=s                        //��ָ����ַ�����λ
    len=strlen(s);
    for(int i=0;i<strlen(s);i++)
    {
        if(s[i]>='0' && s[i]<='9') times+=s[i]-'0';
        else if(s[i]=='!') printf("\n");
        else
        {
            for(int j=1;j<=times;j++)

                {
                    if(s[i]=='b') printf(" ");
                    else printf("%c",s[i]);
                }
            times=0;
        }
    }
}

/**�ڻس��ո񶼱������ַ�ʱ��Ҫ��gets������scanf**/
