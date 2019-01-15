#include <bits/stdc++.h>
using namespace std;
struct node {
	node *prev;
	int n, chs;
};
node mp[1 << 22 + 1];
int vis[1 << 22 + 1];
void check(string s) {
	map<string, int> mmp;
	for (int i = 0; i < s.length();++i) {
		for (int j = 1; j <= s.length() - i; ++j) {
			mmp[s.substr(i, j)]++;
		}
	}
	cout << mmp.size() << endl;;
}
int main() {
	int k;
	cin >> k;
	if (k <= 1 << 12) {
		for (int i = 0; i < k; ++i)
			putchar('a');
		cout << endl;
		return 0;
	}
	for (int i = 1; i <= 200; ++i) {
		mp[i].prev == nullptr;
		mp[i].n = i;
		mp[i].chs = i;
		vis[i] = 1;
	}
	for (int i = 1; i <= k; ++i) {
		int l1 = mp[i].chs;
		for (int l2 = 1; l2 <= 150; ++l2) {
			int s = i + l2 *(1 + l1);
			if (vis[s])
				continue;
			else {
				vis[s] = 1;
				mp[s].prev = &mp[i];
				mp[s].n= l2;
				mp[s].chs = l2 + mp[i].chs;
			}
			if (s == k)
			{
				string ans="";
				char cur = 'a';
				node *now = &mp[s];
				while (now) {
					for (int k = 0; k < now->n; ++k)
						putchar(cur);
					++cur;
					now = now->prev;
				}
				cout << ans<< endl;
				//cout << ans.length()<<endl;
				//check(ans);
				return 0;
			}
		}
	}
	return 0;
}