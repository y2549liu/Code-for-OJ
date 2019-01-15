#include <bits/stdc++.h>
using namespace std;
int main() {
	int t,n;
	cin >> t;
	int dp[101][101], diaosi[101], sum[101];//dp[i][j] represents the minimum sum of diaosi between i and j
	for (int cases = 1; cases <= t; ++cases) {
		cin >> n;
		memset(dp, 0, sizeof(dp));
		memset(sum, 0, sizeof(sum));
		
		for (int i = 1; i <= n; ++i) {
			cin >> diaosi[i];
			sum[i] = sum[i - 1] + diaosi[i];
			for (int j = i + 1; j <= n; ++j)
				dp[i][j] = 0x7fffffff;
		}
		for (int len = 1; len < n; ++len) {
			for (int i = 1; i <= n - len; ++i) {
				//enumerate the show time of the i th people
				//we can let him go on to the stage directly
				//or put him into the black room
				for (int k = i; k <= i + len; ++k) {
					dp[i][i + len] = min(dp[i][i + len],
						dp[i + 1][k] + 
						(k - i)*diaosi[i] + 
						dp[k+1][i+len] + 
						(k+1-i)*(sum[i+len]-sum[k]));
				}
			}
		}
		printf("Case #%d: %d\n", cases, dp[1][n]);
	}
	return 0;
}