#include <bits/stdc++.h>
using namespace std;
int dp[10001];

int main() {
	int n, m,a;
	cin >> n >> m;
	dp[0] = 1;
	for (int i = 0; i < n; ++i) {
		cin >> a;
		for (int j = m; j >= a; --j) {
			dp[j] += dp[j - a];
		}
	}
	cout << dp[m];
	return 0;
}