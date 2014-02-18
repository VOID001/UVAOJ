#define LOCAL
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<string.h>
#define MAX 1100

int cmp_string(const void*a, const void* b);
void ptdash();				//Print ----------...
int read_in();
void solve();

char ls[MAX][80];
int n, R, T, smax;

int main(void)
{
#ifdef LOCAL
	//freopen("400.in", "r", stdin);
	freopen("400.out", "w", stdout);
#endif
	while (read_in())
	{
		ptdash();
		solve();
	}
	return 0;
}

int cmp_string(const void *a, const void *b)
{
	char* stra = (char*)a;
	char* strb = (char*)b;
	return strcmp(stra, strb);
}

void ptdash()
{
	for (int pt = 1; pt <= 60; pt++) printf("-");
	printf("\n");
	return ;
}

int read_in()
{
	memset(ls, 0, sizeof(ls));
	int st=scanf("%d", &n);
	if (st == EOF) return 0;
	smax = 0;
	for (int i = 0; i < n; i++)
	{
		scanf("%s", ls[i]);
		int len = strlen(ls[i]);
		if (smax < len) smax = len;
	}
	return 1;									//Õý³£·µ»Ø
}

void solve()
{
	T = 60 /(smax+2);
	if (!T) T++;
	R = n / T;
	int rest = n%T;
	if (rest) R++;
	qsort(ls, n, sizeof(ls[0]), cmp_string);
	for (int i = 0; i < (rest == 0 ? R:R-1); i++)
	{
		for (int j = 0; j < T; j++)
		{
			int len = strlen(ls[i + j*R]);
			printf("%s  ", ls[i + j*R]);
			for (int pt = 0; pt < smax - len; pt++) printf(" ");
		}
		printf("\n");
	}
	if (rest)
	{
		for (int i = 0; i<rest; i++)
		{
			int len = strlen(ls[R + i*R-1]);
			printf("%s",ls[R+i*R-1]);
			if (i != rest - 1){ printf("  "); for (int pt = 0; pt < smax - len; pt++) printf(" "); }
		}
	}
	return ;
}