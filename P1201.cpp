#include <bits/stdc++.h>
using namespace std;
int main() {
	int n; cin >> n;
	map<string, int> name;
	string str, namearr[20];
	for (int i = 0; i < n; ++i) {
		cin >> namearr[i];
		name[namearr[i]] = i;
	}
	int sent[20] = { 0 }, get[20] = { 0 }, tot, friends;
	for (int i = 0; i < n; ++i) {
		cin >> str;
		int no = name[str];
		cin >> tot >> friends;
		if (friends == 0)
			continue;
		for (int j = 0; j < friends; ++j) {
			cin >> str;
			get[name[str]] += tot / friends;
		}
		sent[no] = tot/friends *friends;
	}
	for (int i = 0; i < n; ++i) 
		cout<< namearr[i] << " "<<get[i]-sent[i]<<endl;

	return 0;
}