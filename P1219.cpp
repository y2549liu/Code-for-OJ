#include <bits/stdc++.h>
using namespace std;
int n, tot = 0;
bool visited[3][26];
int ans[14];
void DFS(int line) {
	if (line > n) {
		++tot;
		if (tot <= 3) {
			for (int i = 1; i <= n; ++i) {
				cout << ans[i] << " ";
			}
			cout << endl;
		}
		return;
	}
	for (int i = 1; i <= n; ++i) {
		if (!visited[0][i] && !visited[1][line + i] && !visited[2][line + n - i]) {
			visited[0][i] = visited[1][line + i] = visited[2][line + n - i] = 1;
			ans[line] = i;
			DFS(line + 1);
			visited[0][i] = visited[1][line + i] = visited[2][line + n - i] = 0;
		}
	}
}
int main() {
	cin >> n;
	DFS(1);
	cout << tot;
	return 0;
}