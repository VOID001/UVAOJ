//		400 ��ȫ��д
//		���ǵ� 60/60+2=0������ ���ǵ� �ո��������� 
//		�ڵ�����4��֮�����д���� ����������

#define LOCAL
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//Function Prototype
int read_in();
void solve();
int cmp(const void *a, const void *b);
//END

#define MAX 110
char ls[MAX][65];			//����ǰ�洢��λ��
int n;
int maxlen;

int main(void)
{
	while (read_in())
	{
		solve();
	}
	return 0;
}

int read_in()
{
	maxlen = 0;
	memset(ls, 0, sizeof(ls));
	int st=scanf("%d", &n);
	if (st==EOF) return 0;
	for (int i = 0; i < n; i++)
	{
		scanf("%s", ls[i]);
		if (maxlen < strlen(ls[i])) maxlen = strlen(ls[i]);
	}
	return 1;
}

int cmp(const void *a, const void *b)
{
	char *sa = (char*)a;
	char *sb = (char*)b;
	return strcmp(sa, sb);
}

void solve()
{
	qsort(ls, n, sizeof(ls[0]), cmp);

	for (int cnt = 0; cnt < 60; cnt++) printf("-");
	printf("\n");						//��ӡ��ʮ������
	//int res = 60 %(maxlen + 2);
	int  T = 60 / (maxlen + 2);
	if (!T) T++;
	int res = n%T;
	int lines = n / T;
	if (res) lines++;

	for (int i = 0; i < lines; i++)
	{
		for (int j = 0; j < T; j++)
		{
			//char *tmp = "";
			//strcpy(tmp, ls[i + T*j]);
			int len = strlen(ls[i + (lines)*j]);
			if (!strcmp(ls[i + (lines)*j], ""))break;
			printf("%s", ls[i + (lines)*j]);
			for (int i = 1; i <= maxlen - len; i++) printf(" ");
			if (j < T - 1) printf("  ");
		}
		printf("\n");
	}
	return;
}


// /�����˸�������֮������һ�ι��� ���� ~~~~~~~ ���ﻹҪŬ��Ŷ������