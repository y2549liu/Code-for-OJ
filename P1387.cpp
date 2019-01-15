#include <bits/stdc++.h>
using namespace std;
bool num[102][102];
int dp[102][102];
int Min(const int &a, const int &b, const int &c) {
	return min(min(a, b), c);
}
int main() {
	int n, m,ans=0;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> num[i][j];
			ans = max(ans, dp[i][j] = num[i][j] ? (1 + Min(dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1])) : 0);
		}
	}
	cout << ans;
	return 0;
}