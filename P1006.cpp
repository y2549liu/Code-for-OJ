#include <bits/stdc++.h>
using namespace std;
#define maxn 52
int dp[2 * maxn][maxn][maxn],a[maxn][maxn];
template<class T>
T Max(vector<T> arr){
	T ans = arr[0];
	for (int i = 1; i < arr.size(); ++i) {
		ans = max(ans, arr[i]);
	}
	return ans;
}

int main() {
	int m, n;
	cin >> m >> n;
	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> a[i][j];
		}
	}
	for (int k = 3; k < m + n; ++k) {
		for (int i = 1; i < n ; ++i) {
			for (int j = i + 1; j <= n; ++j) {
				dp[k][i][j] = a[k-i][i]+a[k-j][j]+Max(vector<int>({ dp[k - 1][i][j],dp[k - 1][i - 1][j],dp[k - 1][i - 1][j - 1],dp[k - 1][i][j - 1] }));
			}
		}
	}
	cout << dp[m + n - 1][n-1][n];
	return 0;
}