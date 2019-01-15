#include <bits/stdc++.h>
using namespace std;

#define maxn 100001
int cake[maxn][11],dp[maxn][11];
int main() {
	ios::sync_with_stdio(false);
	int n,loc,t,maxt=0;
	while (cin >> n && n) {
		memset(cake, 0, sizeof(cake));
		for (int i = 0; i < n; ++i) {
			cin >> loc >> t;
			++cake[t][loc];
			if (t > maxt) maxt = t;
		}
		for (int j = 0; j <= 10; ++j)
			dp[0][j] = 0x80000000;
		dp[0][5] = 0;
		for (int i = 1; i <= maxt; ++i) {
			for (int j = 0; j <= 10; ++j) {
				dp[i][j] = dp[i - 1][j];
				if (j)		dp[i][j] = max(dp[i][j], dp[i - 1][j - 1]);
				if (j!=10)	dp[i][j] = max(dp[i][j], dp[i - 1][j + 1]);
				dp[i][j] += cake[i][j];
			}
		}
		int ans = 0;
		for (int j = 0; j <= 10; ++j)
			ans = max(ans, dp[maxt][j]);
		cout << ans << endl;
	}
	return 0;
}