#include<iostream>
#include<cstdio>
#include<string>
#include<cstdlib>
#include<algorithm>
#include<vector>
using namespace std;
#define MAX 220		//�ô���� 
void init();

string Vlst="AUEOI";							//����V �� C ��
string Clst = "JSBKTCLDMVNWFXGPYHQZR";		

vector<pair<string,int> > NUM;
int main(void)
{
	//freopen("10785.out", "w", stdout);
	init();
	int cnt;
	scanf("%d",&cnt);
	for (int i = 0; i < cnt; i++)
	{
		int in;
		scanf("%d", &in);
		printf("Case %d: ", i + 1);
		cout << NUM[in - 1].first;
		printf("\n");
	}
}

void init()
{
	for (int i = 1; i <=210;i++)
	{
		string tmp;
		int curposv=0, curposc=0;				//�䵱ָ��
		int cntV, cntC;							//�䵱������
		cntV = cntC = 0;
		int val = 0;
		while (tmp.size() != i)
		{
			tmp += Vlst[curposv];
			val += (Vlst[curposv] - 'A') % 8 + 1;
			cntV++;
			if (tmp.size() == i) break;
			tmp += Clst[curposc];
			val += (Clst[curposc] - 'A') % 8 + 1;
			cntC++;
			if (tmp.size() == i) break;
			if (cntV == 21) { cntV = 0; curposv++; }
			if (cntC == 5){ cntC = 0; curposc++; }
		}
		//�����ֵ������� �������ⶼ�Ǵ�д���ÿ��Ǵ�Сд����
		for (int m = 0;m < tmp.size()-1; m += 2)				
		{
			if (m<tmp.size())
			for (int n = m + 2; n < tmp.size();n+=2)
			if (n<tmp.size() && tmp[n] < tmp[m])
			{
				char t = tmp[m];
				tmp[m] = tmp[n];
				tmp[n] = t;
			}
		}
		for (int m = 1; m < tmp.size(); m += 2)
		{
			if (m<tmp.size())
			for (int n = m + 2; n < tmp.size(); n += 2)
			if (n<tmp.size() && tmp[n] < tmp[m])
			{
				char t = tmp[m];
				tmp[m] = tmp[n];
				tmp[n] = t;
			}
		}
		//��ʵ���pair����ûʲô�ã�ֱ��string�Ϳ��� �ոտ�ʼ����û�������µĲо֡����� STL
		NUM.push_back(make_pair(tmp,val));
	}
	return;
}