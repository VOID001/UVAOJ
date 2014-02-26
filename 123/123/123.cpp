#include<cstdio>
#include<string>
#include<iostream>
#include<algorithm>
#include<set>
#include<map>
#include<cctype>
#define MAX 220
using namespace std;

int main(void)
{
	set<string> ig;
	string igs;							//�����б�
	string title;						//�����б�
	multimap<string, string> res;
	while (cin >> igs && igs != "::")
		ig.insert(igs);
	getchar();							//�Իس� 
	while (getline(cin, title))
	{
		int len = title.size();
		for (int i = 0; i < len; i++)
			title[i] = tolower(title[i]);
		for (int i = 0; i < len; i++)
		{
			if (!isalpha(title[i])) continue;
			string key;								//��¼�ؼ��ʵ��ַ���-- key
			int current_pos = i;					//��¼��ǰλ�� �ñ���������滻 �ѹؼ����滻Ϊ��д
			while (i < title.size() && isalpha(title[i]))
				key += title[i++];					//�ѹؼ���copy��key ��ʱ��������String��ķ���
			if (!ig.count(key))
			{
				int len0 = key.size();
				for (int j = 0; j < len0; j++)
					key[j] = toupper(key[j]);
				string tmp = title;
				tmp.replace(current_pos, key.size(), key);
				res.insert(make_pair(key,tmp));								//��Ϊmultimap��һ�Զ� ���Բ���Ҫ�� make_pair
			}
		}
	}
	for (multimap<string, string>::iterator i = res.begin(); i != res.end(); i++)
		cout << i->second << endl;
	getchar();
	return 0;
}