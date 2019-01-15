#include <bits/stdc++.h>

using namespace std;

int c[10][10];
int vis[10],cnt[10];
void dfs(int x) {
	vis[x] = 1;
	for (int i = 0; i < 10; ++i) 
		if (c[x][i] && !vis[i]) 
			dfs(i);
}
void count() {
	for (int i = 0; i < 10; ++i) {
		memset(vis, 0, sizeof(vis));
		dfs(i);
		for (int j = 0; j < 10; ++j)
			if (vis[j])
				++cnt[i];
	}
}
string ans="1";
string mul(string str, int n) {
	if (n == 1)
		return str;
	string ans;
	ans.resize((str.length() + 1));
	for (int i = 0; i < str.length(); ++i) {
		ans[i] += (str[i] - '0')*n;
		ans[i + 1] += ans[i] / 10;
		ans[i] %= 10;
		ans[i] += '0';
	}
	ans[str.length()] += '0';
	if (ans[str.length()] == '0')
		ans.resize(str.length());
	return ans;
}
int main() {
	int k;
	string n;
	cin >> n >> k;
	for (int i = 0; i < k; ++i) {
		int a, b;
		cin >> a >> b;
		c[a][b] = 1;
	}
	count();
	for (int i = 0; i < n.length(); ++i) {
		ans=mul(ans,cnt[ (n[i]-'0')]);
	}
	reverse(ans.begin(), ans.end());
	cout << ans;
	return 0;
}