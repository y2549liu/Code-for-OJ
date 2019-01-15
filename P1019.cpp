/* https://www.luogu.org/problemnew/show/P1019 */
#include <bits/stdc++.h>
using namespace std;

int visited[21];
int edge[21][21];
int n,ans=1;
string word[21];
int canlink(string &a, string &b) {
	int alen = a.length(), blen = b.length();
	/*
	if ((alen >= blen && a.find(b) != string::npos) || (alen < blen && b.find(a) != string::npos))
		return 0;
	*/
	for (int i = 1, len = min(alen,blen); i < len; ++i) {
		if (a.substr(alen - i, i) == b.substr(0, i)) 
			return i;
	}
	return 0;
}
void DFS(int now, int len) {
	ans = max(ans, len);
	for (int i = 0; i < n; ++i) {
		if (edge[now][i] && visited[i] < 2) {
			++visited[i];
			DFS(i, len + word[i].length() - edge[now][i]);
			--visited[i];
		 }
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i <= n; ++i) {
		cin >> word[i];
		if (i == n) {
			word[i] = ' ' + word[i]; //把起始字符当成字符串
		}		
		for (int j = 0; j < i; ++j) {
			edge[i][j] = canlink(word[i], word[j]);
			edge[j][i] = canlink(word[j], word[i]);
		}
		edge[i][i]= canlink(word[i], word[i]);
	}
	DFS(n, ans);
	cout << ans;
	return 0;
}