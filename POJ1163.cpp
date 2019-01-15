#include <bits/stdc++.h>
using namespace std;
#define maxn 102
int dp[maxn][maxn],num[maxn][maxn];

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i){
		for (int j = 1; j <= i; ++j) {
			cin >> num[i][j];
			dp[i][j] = num[i][j] + max(dp[i - 1][j], dp[i - 1][j - 1]);
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i)
		ans = max(ans, dp[n][i]);
	cout << ans;
	return 0;
}