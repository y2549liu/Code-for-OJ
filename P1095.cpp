#include<bits/stdc++.h>
using namespace std;

int dp[300001] = { 0 };
int main() {
	int m, s, t;
	cin >> m >> s >> t;
	int i;
	for (i = 1; i <= t; ++i) {
		if (m >= 10) {
			dp[i] = dp[i - 1] + 60;
			m -= 10;
		}
		else {
			dp[i] = dp[i - 1];
			m += 4;
		}
		if (dp[i] >= s)
			break;
	}
	for (i=max(i-7,1); i <= t; ++i) {
		if (dp[i] < 17 + dp[i - 1]) 
			dp[i] = 17 + dp[i - 1];
		if (dp[i] >= s) {
			cout << "Yes\n" << i;
			exit(0);
		}
	}
	cout << "No\n" << dp[t];
	return 0;
}