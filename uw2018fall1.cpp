#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	bool vis[1 << 15 + 1] = { 0 };
	int t;
	for (int i = 1; i < n; ++i) {
		cin >> t;
		vis[t] = 1;
	}
	for (int i = 1; i <= n; ++i) {
		if (vis[i] == 0)
		{
			cout << i << endl;
			break;
		}
	}
	return 0;
}