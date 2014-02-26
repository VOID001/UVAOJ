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
	string igs;							//忽略列表
	string title;						//标题列表
	multimap<string, string> res;
	while (cin >> igs && igs != "::")
		ig.insert(igs);
	getchar();							//吃回车 
	while (getline(cin, title))
	{
		int len = title.size();
		for (int i = 0; i < len; i++)
			title[i] = tolower(title[i]);
		for (int i = 0; i < len; i++)
		{
			if (!isalpha(title[i])) continue;
			string key;								//记录关键词的字符串-- key
			int current_pos = i;					//记录当前位置 好便于下面的替换 把关键词替换为大写
			while (i < title.size() && isalpha(title[i]))
				key += title[i++];					//把关键词copy到key 这时就体现了String类的方便
			if (!ig.count(key))
			{
				int len0 = key.size();
				for (int j = 0; j < len0; j++)
					key[j] = toupper(key[j]);
				string tmp = title;
				tmp.replace(current_pos, key.size(), key);
				res.insert(make_pair(key,tmp));								//因为multimap是一对儿 所以插入要用 make_pair
			}
		}
	}
	for (multimap<string, string>::iterator i = res.begin(); i != res.end(); i++)
		cout << i->second << endl;
	getchar();
	return 0;
}