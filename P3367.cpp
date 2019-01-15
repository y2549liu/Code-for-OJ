#include <bits/stdc++.h>
using namespace std;
const int maxn = 10001;
int n, m;
int pa[maxn];

int  find_parent(const int  &x) {
	return (pa[x] == x) ? x : (pa[x] = find_parent(pa[x]));
}
int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	int  act, a, b, paa, pab;
	string ans[2] = {"N\n", "Y\n"};
	for (int  i = 1; i <= n; ++i)
		pa[i] = i;
	for (int i = 0; i < m; ++i) {
		cin >> act >> a >> b;
		paa = find_parent(a); pab = find_parent(b);
		if (act == 1) {
			if ((paa+pab)&1)
				pa[paa] = pab;
			else 
				pa[pab] = paa;
		}
		else {
			cout << ans[paa == pab] ;
		}
	}
	return 0;
}