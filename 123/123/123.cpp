#include<cstdio>
#include<cctype>
#include<string>
#include<iostream>
#include<map>			//multimap ����
#include<set>			//set
#include<algorithm>		//count ����
using namespace std;


int main(void)
{
	set<string> ig;						//���Լ���
	multimap<string, string> res;		//�������
	string igs;							//��ȡ�����ִ�
	string title;						//��ȡ�����ִ�
	while (cin >> igs && igs != "::")
		ig.insert(igs);
	getchar();							//�����˳Իس�
	while (getline(cin, title))
	{
		for (int i = 0; i < title.size(); i++)
			title[i] = tolower(title[i]);
		for (int i = 0; i < title.size(); i++)
		{
			if (!isalpha(title[i])) continue;
			string key;					//��Źؼ���
			int cur_pos = i;			//�Լ�д����������������� �Ǻ�~~ 
			while (i < title.size() && isalpha(title[i]))
			{
				key += title[i++];
			}
			if (!ig.count(key))
			{
				string tmp = title;
				for (int j = 0; j < key.size(); j++)
					key[j] = toupper(key[j]);
				tmp.replace(cur_pos, key.size(), key);
				res.insert(make_pair(key, tmp));
			}
		}
	}
	for (multimap<string, string>::iterator i = res.begin(); i != res.end(); i++)
		cout << i->second << endl;
	return 0;
}

//�����Լ�����д�İ� ���������������� �Լ���д�����ִ�����Ҫ�ܺõĹ���