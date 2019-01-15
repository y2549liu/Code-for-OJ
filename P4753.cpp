/* https://www.luogu.org/problemnew/show/P4753 */
#include  <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	int n, m, s;
	cin >> n >> m >> s;
	vector<int> pos(m+2);
	pos[m + 1] = n;
	for (int i = 1; i <= m; ++i) 
		cin >> pos[i];
	if (pos[1] < s || n - pos[m] < s) {
		cout << "NO\n";
		return 0;
	}
	vector<bool> visited(m + 2);
	vector<int> pass(m + 2);
	int now = 0, cnt = 0;
	for (int i = 1; i <= m + 1; ++i) {
		if (pos[i] - now >= s) {
			pass[cnt++] = i;
			now = pos[i];
			visited[i] = true;
		}
	}
	for (int i = m + 1; i >= 0; --i) {
		if (!visited[i] && (now - pos[i] >= s)) {
			now = pos[i];
			pass[cnt++] = i;
			visited[i] = true;
		}
	}
	if (cnt == m + 2) {
		cout << "YES\n";
		for (int i = 0; i <= m; ++i) {
			cout << pass[i] << " ";
		}
		cout << pass[m + 1];
	}
	else
		cout << "NO";

	return 0;
}