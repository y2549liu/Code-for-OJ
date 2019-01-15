#include<bits/stdc++.h>
using namespace std;
/*
int ans = 0, n,k;
void dfs(int start, int round) {
	if (start < 0)
		start += n;
	else if (start >= n)
		start -= n;
	if (start == 0 && round == 0) {
		++ans;
		return;
	}
	else if (min(start, n - start) > round)
		return;
	else if (min(start, n - start) == round)
	{
		ans += 1 + (start == n - start);
		return;
	}
	dfs(start - 1, round - 1);
	dfs(start + 1, round - 1);
}
*/

int n, m;
int dp[30][30];


int main() {
	cin >> n >> m;
	dp[0][0] = 1;
	for (int t = 1; t <= m; ++t) {
		for (int s = 0; s < n; ++s) {
			dp[s][t] = dp[(s + 1 + n)%n][t - 1] + dp[(s - 1+n)%n][t - 1];
		}
	}
	cout << dp[0][m];
	return 0;
}