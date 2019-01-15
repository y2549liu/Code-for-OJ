#include <bits/stdc++.h>
using namespace std;
const int maxn = 2502;
int fish[maxn][maxn],vertical[maxn][maxn],horizontal[maxn][maxn],dp[maxn][maxn];

int min(int a,int b, int c) {
	return min(min(a, b), c);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m,ans=0;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> fish[i][j];
			if (!fish[i][j]) {
				horizontal[i][j] = horizontal[i][j - 1] + 1;
				vertical[i][j] = vertical[i - 1][j] + 1;
			}
			if (fish[i][j]) 
				dp[i][j] = 1 + min(dp[i - 1][j - 1], horizontal[i][j - 1], vertical[i - 1][j]);
			ans = max(ans, dp[i][j]);
		}
	}
	memset(dp, 0, sizeof(dp));
	memset(horizontal, 0, sizeof(horizontal));

	for (int i = 1; i <= n; ++i) 
		for (int j = m; j >= 1; --j) {
			horizontal[i][j] = (fish[i][j]) ? 0 : (horizontal[i][j + 1] + 1);
			if (fish[i][j])
				dp[i][j] = 1 + min(dp[i - 1][j + 1], horizontal[i][j + 1], vertical[i - 1][j]);
			ans = max(ans, dp[i][j]);
		}
	cout << ans;
	return 0;
}