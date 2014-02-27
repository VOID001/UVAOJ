#include<stdio.h>
#include<iostream>
#include<string>
#include<algorithm>
#include<map>
#include<cctype>

using namespace std;
string refer = "ABCDEFGHIJKLMNOPRSTUVWXY";

int main(void)
{
	freopen("755.out", "w", stdout);
	int cases;
	int lines;
	map<string, int> numlst;
	scanf("%d", &cases);
	for (int oo = 0; oo < cases; oo++)
	{
		numlst.clear();
		scanf("%d", &lines);
		string telnum;
		string telNUM;
		//getchar();
		for (int i = 0; i < lines; i++)
		{
			telNUM.clear();
			cin >> telnum;
			int size1 = telnum.size();
			for (int j = 0; j <size1 ; j++)
			{
				if (telnum[j] == '-') continue;
				else if (isalpha(telnum[j]))
				{
					for (int cnt = 0; cnt < 24;cnt++)
					if (telnum[j] == refer[cnt]) { telNUM += (char)((cnt / 3) + 2+'0'); break; }
				}
				else telNUM += telnum[j];
			}
			if (!numlst.count(telNUM))
				numlst.insert(make_pair(telNUM, 1));
			else
			{
				for (map<string, int>::iterator ii = numlst.begin(); ii != numlst.end(); ii++)
				{
					if ((*ii).first == telNUM) { (*ii).second++; break; }
				}
			}
		}
		for (map<string, int>::iterator ii = numlst.begin(); ii != numlst.end(); ii++)
		{
			if ((*ii).second != 1)
			{
				for (int j = 0; j < 8; j++)
				{
					if (j == 3) printf("-");
					else printf("%c", (*ii).first[j]);
				}
				printf(" %d\n", (*ii).second);
				//printf("\n");
			}
		}
		printf("\n");
	}
	while (1) getchar();
	return 0;
}