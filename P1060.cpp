
int dp[30001];
int main(){
	int n,m,price,value;
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		cin >> price >> value;
		value *= price;
		for (int i = n; i >= price; --i)
			dp[i] = max(dp[i], dp[i - price] + value);
	}
	cout << dp[n];
	return 0;
}