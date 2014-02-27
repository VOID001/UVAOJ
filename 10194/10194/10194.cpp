/**UVAOJ 10194 �Զ����Ŀ��������**/
#define LOCAL
#include<iostream>
#include<stdio.h>
#include<set>
#include<string>
#include<algorithm>
#include<vector>				//SET �����Զ���sort����ô�� ����vector����ͽ����
using namespace std;

typedef struct team
{
	string name;
	//int rank=0;
	int points=0;
	int played=0;
	int wins=0;
	int ties = 0;
	int lose = 0;					//��ı�������
	int losses = 0;					//���򼸸�
	int differ = 0;
	int goals = 0;
}team;

bool cmp(const team *a, const team*b)					//�Զ���ȽϺ���
{
	if (a->points > b->points) return true;
	else if (a->points < b->points) return false;
	else
	{
		if (a->wins>b->wins) return true;
		else if (a->wins < b->wins) return false;
		else
		{
			if (a->differ>b->differ) return true;
			else if (a->differ < b->differ) return false;
			else
			{
				if (a->goals>b->goals) return true;
				else if (a->goals < b->goals) return false;
				else
				{
					if (a->played<b->played) return true;
					else if (a->played > b->played) return false;
					else
					{
						string tmpa, tmpb;
						tmpa = a->name;
						tmpb = b->name;
						for (int oo = 0; oo < tmpa.size(); oo++) tmpa[oo] = tolower(tmpa[oo]);
						for (int oo = 0; oo < tmpb.size(); oo++) tmpb[oo] = tolower(tmpb[oo]);
						return tmpa < tmpb;
					}
				}
			}
		}
	}
}

int main(void)
{
#ifdef LOCAL
	freopen("10194.out","w",stdout);
#endif
	string game;
	int matches;
	int num;
	scanf("%d", &matches);
	getchar();							//�Իس�
	for (int i = 0; i < matches; i++)
	{
		getline(cin, game);
		scanf("%d", &num);
		getchar();						//�Իس�
		vector<team*> T;
		team tmp[32];
		for (int oo = 0; oo < num; oo++)
		{
			getline(cin, tmp[oo].name);
			T.push_back(&tmp[oo]);
		}						//�������С����Ϣ
		scanf("%d", &num);		//��������
		getchar();				//�ٳԻس�
		for (int oo = 0; oo < num; oo++)
		{
			string data;		//������Ϣ������
			getline(cin, data);
			string cur;
			int cnt = 0;
			team *curteama,*curteamb;
			int scorea = 0 , scoreb = 0;
			while (data[cnt] != '#') cur += data[cnt++];
			for (vector<team*>::iterator i = T.begin(); i != T.end(); i++)
			if ((*i)->name == cur) curteama = *i;	//��λ����ǰ����a
			cnt++;
			while (data[cnt] != '@')										//��ȡ�ȷ� �ȶ� a team
			{
				scorea = scorea * 10 + data[cnt] - '0';
				cnt++;
			}
			cnt++;
			while (data[cnt] != '#')
			{
				scoreb = scoreb * 10 + data[cnt] - '0';						//�ٶ�b team
				cnt++;
			}
			cur.clear();													//�����������cur
			cnt++;
			while (data[cnt] != '\0') cur += data[cnt++];					//Ȼ���ټ�¼��һ����������										
			for (vector<team*>::iterator i = T.begin(); i != T.end(); i++)		//��λ����ǰ����b
			if ((*i)->name == cur) curteamb = *i;
			//��ʼ�ж� ����¼
			//curteama->played += scorea;
			//curteamb->played += scoreb;
			curteama->losses += scoreb;
			curteamb->losses += scorea;
			curteama->goals += scorea;
			curteamb->goals += scoreb;
			curteama->played++;
			curteamb->played++;
			if (scorea > scoreb)											//��ΪaӮ��b a bƽ a��� b�������
			{
				curteama->wins++;
				curteamb->lose++;
				curteama->points += 3;
				curteamb->points += 0;
			}
			else if (scorea < scoreb)
			{
				curteamb->wins++;
				curteama->lose++;
				curteamb->points += 3;
				curteama->points += 0;
			}
			else if (scorea == scoreb)
			{
				curteama->ties++;
				curteamb->ties++;
				curteama->points++;
				curteamb->points++;
			}
			//�жϽ���
		}
		for (vector<team*>::iterator i = T.begin(); i != T.end(); i++)
		{
			(*i)->differ = (*i)->goals - (*i)->losses;
		}
		sort(T.begin(), T.end(), cmp);
		int count = 1;
		cout << game << endl;
		for (vector<team*>::iterator i = T.begin(); i != T.end(); i++)
		{
			cout << count++ << ") " << (*i)->name << " " << (*i)->points << "p, " << (*i)->played << "g (" << (*i)->wins << "-" << (*i)->ties << "-" << (*i)->lose << "), " << (*i)->differ << "gd (" << (*i)->goals << "-" << (*i)->losses << ")";
			printf("\n");
		}
		if(i<matches-1) printf("\n");
	}
	//getchar();
	return 0;
}


/**
Most points earned.
Most wins.
Most goal difference (i.e. goals scored - goals against)
Most goals scored.
Less games played.
Lexicographic order.			����Ƚ��ǲ��ִ�Сд�ģ�������Aa����ͬ��Ȩ��
**/