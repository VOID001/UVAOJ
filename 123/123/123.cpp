#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 10000

int cmp(const void *a, const void *b);
char iglst[55][30];
char titles[200][MAX];

int main(void)
{
	int oo = 0;
	while (gets(iglst[oo]))
	{
		if (!strcmp(iglst[oo], "::")) break;
		else oo++;
	}
	int cnt = 0;
	while (gets(titles[cnt]) != NULL)
	{
		char tmp[10000];
		strcpy(tmp, titles[cnt]);
		for (int i = 0; i <= oo; i++)
		{
			if (strstr(tmp, iglst[oo]) != NULL)
			{
				char *pt = strstr(tmp, iglst[oo]);
				while (*pt != ' ')
				{
					*pt = " ";
					pt++;
				}
			}
		}
	}
}