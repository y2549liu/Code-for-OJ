#include <bits/stdc++.h>
using namespace std;

bool vis[1001];
int main() {
	int n,p[1001];
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> p[i];
	for (int i = 1; i <= n; ++i) {
		memset(vis, 0, sizeof(vis));
		int now = i;
		while (!vis[now]) {
			vis[now] = 1;
			now = p[now];
		}
		cout << now << " ";
	}
	return 0;
}