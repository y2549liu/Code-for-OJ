#include<bits/stdc++.h>
using namespace std;

int dp[41][41][41][41], num[351], card[5];

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		cin >> num[i];
	int t;
	for (int i = 0; i < m; ++i) {
		cin >> t;
		card[t]++;
	}
	****dp = num[0];
	for (int a=0;a<=card[1];++a)
		for (int b = 0; b <= card[2]; ++b)
			for (int c = 0; c <= card[3]; ++c)
				for (int d = 0; d <= card[4]; ++d) {
					int now = a + 2 * b + 3 * c + 4 * d;
					if (a)
						dp[a][b][c][d] = max(dp[a][b][c][d], dp[a - 1][b][c][d] + num[now]);
					if (b)
						dp[a][b][c][d] = max(dp[a][b][c][d], dp[a][b - 1][c][d] + num[now]);
					if (c)
						dp[a][b][c][d] = max(dp[a][b][c][d], dp[a][b][c - 1][d] + num[now]);
					if (d)
						dp[a][b][c][d] = max(dp[a][b][c][d], dp[a][b][c][d - 1] + num[now]);
				}
	cout << dp[card[1]][card[2]][card[3]][card[4]];
	return 0;
}