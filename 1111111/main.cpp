#include<stdio.h>
int a[500002],b[500002];
int main()
{
    int n,i,j,lie;
    while(scanf("%d",&n)!=EOF)
    {
        lie=0;
        for(i=1;i<=n;i++)
            scanf("%d",&a[i]);
        for(i=1;i<=n;i++)
            scanf("%d",&b[i]);
        //if(n==1) {printf("1\n"); continue;}
        for(i=1;i<=n;i++)
        {
            if(b[i]-i==1||b[i]-i==-1) continue;
            if(b[i]==i) lie++;
            if(b[i]>i)
            {
                for(j=i+1;j<b[i];j++) {if(a[j]>a[i]) lie++; break;}
            }
            if(b[i]<i)
            {
                for(j=i-1;j>b[i];j--) {if(a[j]>a[i]) lie++; break;}
            }
        }
        printf("%d\n",lie);
    }
    return 0;
}
