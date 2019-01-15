#include <bits/stdc++.h>
using namespace std;
struct food {
	long long  a, b, c;
	bool operator<(const food& x) const {
		return (b*x.c < c*x.b);
	}
};
long long dp[100001];
int num[100001][3];
int main() {
	int t, n;
	cin >> t >> n;
	priority_queue<food> foodQ;
	for (int j=0;j<3;++j)
	for (int i = 0, a, b, c; i < n; ++i) {
		cin >> num[i][j];
	}
	for (int i = 0,a,b,c; i < n; ++i) {
		foodQ.push({ num[i][0],num[i][1], num[i][2] });
	}
	while (foodQ.size()) {
		const food &now = foodQ.top();
		for (int i = t; i >= now.c; --i) {
			dp[i] = max(dp[i], dp[i - now.c] + now.a - now.b*i);
		}
		foodQ.pop();
	}
	long long ans = 0;
	for (int i = t; i >= 0; --i) {
		ans = max(ans, dp[i]);
	}
	cout << ans;
	return 0;
}