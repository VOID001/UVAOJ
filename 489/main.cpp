#include<stdio.h>

#define MAX 100000
int main(void)
{
    //freopen("input.txt","r",stdin);
    int round;/**�غ���**/
    char word[MAX];/**Ŀ�굥��**/
    char ans[MAX];/**�û��²�**/

    while(scanf("%d",&round))
    {

        int win;/**��ʤ��� 1 win -1 lose 0 no**/
        int alphabet[27]={0};/**�����к��е���ĸ**/
        int alphaguess[27]={0};/*****��Ҳ²����ĸ****/
        if(round==-1) break;
        scanf("%s",word);
        scanf("%s",ans);
        for(int oo=0;word[oo]!='\0';oo++)
        {
            alphabet[word[oo]-'a']=1;
        }
        int try_game=7;/**�ߴδ������**/
        win=0;
        for(int oo=0;ans[oo]!='\0';oo++)
        {
            if(try_game==0) break;
            if(alphabet[ans[oo]-'a']==1 && alphaguess[ans[oo]-'a']==0) alphaguess[ans[oo]-'a']=1;
            if(alphabet[ans[oo]-'a']==0 && alphaguess[ans[oo]-'a']==0) {alphaguess[ans[oo]-'a']=1; try_game--;}
        }
        int guess=1;/**�жϲ�û�µ� ����µ��� **/
        //for(int oo=0;oo<27;oo++)

        for(int oo=0;oo<27;oo++)
        {
            if(alphabet[oo]==1 && alphabet[oo]!=alphaguess[oo]) guess=0;
        }
        /**�жϻ�ʤ���**/
        if(guess==1) win=1;
        if(guess==0 && try_game>0) win=0;
        if(guess==0 && try_game==0) win=-1;

        printf("Round %d\n",round);
        switch(win)
        {
        case -1:
            printf("You lose.\n");
            break;
        case 0:
            printf("You chickened out.\n");
            break;
        case 1:
            printf("You win.\n");
            break;
        }
    }
}
/**�ҵ��뷨 ������������Ӧ������ a[27] ÿһ���±����һ��Ӣ����ĸ ��a[3]=0ʱ��ζ�� ���ĸ���ĸ�Ѿ����ֹ� **/
