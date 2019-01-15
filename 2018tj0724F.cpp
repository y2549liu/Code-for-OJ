#include <bits/stdc++.h>
using namespace std;
const int maxn = 2001;
typedef long long LL;
LL w[maxn],dp[maxn][1001];
LL square(const LL &x) {
	return x*x;
}
int main() {
	int n, k;
	while (cin >> n >> k) {
		for (int i = 1; i <= n; ++i)
			cin >> w[i];
		sort(w + 1, w + n + 1);
		memset(dp, 0x7f, sizeof(dp));
		for (int i=0;i<=n;++i)
			dp[i][0] = 0;
		//只取排序后相邻的行李，否则可以交换顺序，使得劳累程度下降
		for (int i = 2; i <= n; ++i) {
			for (int j = 1; j <= (i >> 1); ++j) {
				dp[i][j] = min(dp[i - 2][j - 1] + square(w[i] - w[i - 1]), dp[i - 1][j]);
			}
		}
		cout << dp[n][k]<<endl;
	}
	return 0;
}