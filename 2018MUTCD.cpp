#include <bits/stdc++.h>
using namespace std;
struct lr {
	int l, r;
	bool operator<(const lr& x)const {
		return l < x.l;
	}
};
int num[100001];
int main() {
	int t;
	cin >> t;
	while (t--) {
		set<lr> Q;
		memset(num, 0, sizeof(num));
		int n, m;
		cin >> n >> m;
		int l, r;
		for (int i = 0; i < m; ++i) {
			cin >> l >> r;
			Q.insert({ l,r });
		}
		stack<int> used, tot;
		for (int i = 1; i <= n; ++i) {
			tot.push(i);
		}
		auto iter = Q.begin();
		for (int i = 1; i <= n; ++i) {
			if (num[i]) {
				used.push(num[i]);
			}
			else {
				num[i] = 1;
			}
		}
	}
	return 0;
}