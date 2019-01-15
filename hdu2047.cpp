#include <bits/stdc++.h>
using namespace std;
long long dp[42][3];
int main() {
	int n;
	while (cin >> n) {
		memset(dp, 0, sizeof(dp));
		dp[1][0] = 1;//end with e
		dp[1][1] = 1;//end with o
		dp[1][2] = 1;//end with f
		for (int i = 2; i <= n+1; ++i) {
			dp[i][2] = dp[i][0] = dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2];
			dp[i][1] = dp[i - 1][0] + dp[i - 1][2];
		}
		cout << dp[n + 1][0] << endl;
	}
	return 0;
}