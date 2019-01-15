#include <bits/stdc++.h>
using namespace std;


int main() {
	int n, m, k, s;
	while (cin >> n >> m >> k >> s) {
		int dp[101][101],exp,t;
		memset(dp, 0, sizeof(dp));
		int ans = -1;
		for (int i = 0; i < k; ++i) {
			cin >> exp >> t;
			for (int j = t; j <= m; ++j) {
				for (int w = 1; w <= s; ++w) {
					dp[j][w] = max(dp[j][w], dp[j - t][w - 1] + exp);
				}
				
			}
		}
		for (int j = 0; j <= m; ++j) 
			if (dp[j][s] >= n) {
				ans = m - j;
				break;
			}
		cout << ans << endl;
	}
	return 0;
}