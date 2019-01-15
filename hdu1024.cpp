
#include<bits/stdc++.h>
using namespace std;
const int maxn = 1000001;
int num[maxn], dp[maxn], vis[maxn];
int main() {
	ios::sync_with_stdio(false);
	int m,n,maxi;
	while (cin >> m >> n) {
		for (int i = 1; i <= n; ++i) 
			cin >> num[i];
		memset(dp, 0, sizeof(dp));
		memset(vis, 0, sizeof(vis));
		for (int i = 1; i <= m; ++i) {
			// i segment
			maxi = 0x80000000;
			for (int j = i; j <= n; ++j) {
				//the ith segment is ended with num[j-1] or start a new segment;
				dp[j] = max(dp[j - 1] ,vis[j - 1]) + num[j];
				vis[j - 1] = maxi;
				//maxi represent the max sum of the total i segments' sum in [1-j]
				maxi = max(maxi, dp[j]);
			}
			vis[n] = maxi;
		}
		cout << maxi << endl;
	}
	
	return 0;
}