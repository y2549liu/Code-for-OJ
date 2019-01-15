#include <bits/stdc++.h>
using namespace std;

int DP[128];

int main() {
	ios::sync_with_stdio(false);
	int c, m, n;
	cin >> c;
	while (c--) {
		memset(DP, 0, sizeof(DP));
		cin >> n >> m;
		int price, weight, count, maxw=0;
		for (int i = 0; i < m; ++i) {
			cin >> price >> weight >> count;
			//binary optimize
			int cluster = 1;
			while (count >= cluster) {
				for (int j = n; j >= price*cluster; --j) {
					DP[j] = max(DP[j],DP[j - price*cluster] + weight*cluster);
				}
				count -= cluster;
				cluster <<= 1;
			}
			cluster = count;
			for (int j = n; j >= price*cluster; --j) {
				DP[j] = max(DP[j], DP[j - price*cluster] + weight*cluster);
			}
		}
		for (int i = 0; i <= n; ++i) {
			if (DP[i] > maxw)
				maxw = DP[i];
		}
		cout << maxw << endl;
	}
	return 0;
}