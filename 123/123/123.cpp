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
			if (!o.count(t)) {								//����������o�� ��t��ô�Ͳ�ִ�� û�еĻ�˵���ǹؼ��� ִ��
				cout << t << " " << endl;
				for (int j = 0; j < t.size(); j++)
					t[j] = toupper(t[j]);
				string temp = st;							//���������ִ�����
				temp.replace(rec, t.size(), t);				//��replace�ѱ����ִ�temp�� ��ؼ����ִ�λ����ͬ���ַ��滻Ϊ t 
				r.insert(make_pair(t, temp));
			}
		}
	}
	for (multimap<string, string>::iterator i = r.begin(); i != r.end(); i++)		//multimap��������ź���� ��������ʲô˳��Ҫ�о�
		cout << i->second << endl;
	getchar();
	return 0;
}