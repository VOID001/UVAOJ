#include<stdio.h>
#include<math.h>

int main(void)
{
	int n;
	while (scanf("%d", &n) && n!=0)
	{
		int l = ceil((sqrt(1.0*n)));			//lָ��������������Ĳ���
		int lmid= l*l-(l-1);							//lmax���������м��Ǹ���
		int dis = n - lmid;
		//���������
		if (l % 2==0 && dis >= 0) printf("%d %d", l, l - dis);
		else if (l % 2==0 && dis < 0) printf("%d %d", l + dis, l);
		else if (l % 2 && dis>=0) printf("%d %d", l - dis, l);
		else if (l % 2 && dis < 0) printf("%d %d", l, l + dis);
		printf("\n");
	}
	return 0;
}