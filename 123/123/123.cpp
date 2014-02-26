#include <iostream>
#include <cstdio>
#include <string>
#include <map>
#include <set>
#include <cctype>
#include <algorithm>
using namespace std;
const int maxn = 220;

int main() {
	string k, st;
	int a = 0;
	set<string> o;
	multimap<string, string> r;
	while (cin >> k && k != "::")
		o.insert(k);
	getchar();
	while (getline(cin, st)) {
		for (int i = 0; i < st.size(); i++)
			st[i] = tolower(st[i]);
		for (int i = 0; i < st.size(); i++) {
			if (!isalpha(st[i])) continue;
			string t;
			int rec = i;
			while (i < st.size() && isalpha(st[i]))
				t += st[i++];
			//cout << t << " " << endl;;
			if (!o.count(t)) {								//如果这个集合o里 有t那么就不执行 没有的话说明是关键词 执行
				cout << t << " " << endl;
				for (int j = 0; j < t.size(); j++)
					t[j] = toupper(t[j]);
				string temp = st;							//产生标题字串副本
				temp.replace(rec, t.size(), t);				//用replace把标题字串temp中 与关键子字串位置相同的字符替换为 t 
				r.insert(make_pair(t, temp));
			}
		}
	}
	for (multimap<string, string>::iterator i = r.begin(); i != r.end(); i++)		//multimap本身就是排好序的 但是依靠什么顺序还要研究
		cout << i->second << endl;
	getchar();
	return 0;
}