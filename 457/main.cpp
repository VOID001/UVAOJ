#include<stdio.h>

int main (void)
{
    //freopen("output.txt","w",stdout);
    int cases;
    scanf("%d",&cases);                      //�û�������ٴ�
    for(int i=1;i<=cases;i++)
    {
        int pre[42]={0};
        int now[42]={0};
        int DNA[10];                    //�趨DNA����
        pre[20]=now[20]=1;              //�趨��������ϸ�����ܶ�
        for(int oo=0;oo<10;oo++)
            scanf("%d",&DNA[oo]);
        for(int i=1;i<=50;i++)          //��ʼִ��DNA����
        {
            for(int oo=1;oo<=40;oo++)
            {
                if(i!=1) now[oo]=DNA[pre[oo-1]+pre[oo]+pre[oo+1]];
                switch (now[oo])
                {
                case 0:
                    printf(" ");
                    break;
                case 1:
                    printf(".");
                    break;
                case 2:
                    printf("x");
                    break;
                case 3:
                    printf("W");
                    break;
                }
            }
            printf("\n");
            for (int oo=1;oo<=40;oo++)
                pre[oo]=now[oo];
        }
        if(i!=cases) printf("\n");
    }
    return 0;
}

/**Accepted in 1 attempt 2014-1-22-9:04**/
