#include <bits/stdc++.h>
using namespace std;
bool vis[1<<21];
int main() {
	int n,t,t1,ans=0;
	cin >> n;
	set<int> s[2];
	for (int i = 0; i < n; ++i) {
		s[0] = s[1];s[1].clear();
		s[0].insert(0);
		cin >> t;
		for (auto i : s[0]) {
			t1 = t | i;
			if (!vis[t1]) {
				vis[t1] = 1;
				++ans;
			}
			s[1].insert(t1);
		}
	}
	cout << ans;
	return 0;
}