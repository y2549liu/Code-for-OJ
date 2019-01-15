#include  <bits/stdc++.h>
using namespace std;

int DP[1024];
int value[1024], weight[1024];
int main() {
	ios::sync_with_stdio(false);
	int T,n,v;
	cin >> T;
	while (T--) {
		memset(DP, 0, sizeof(DP));
		cin >> n >> v;
		for (int i = 0; i < n; ++i)
			cin >> value[i];
		for (int i = 0; i < n; ++i)
			cin >> weight[i];

		for (int i = 0; i < n; ++i) {
			for (int j = v; j >= weight[i]; --j) {
				DP[j] = max(DP[j], DP[j - weight[i]] + value[i]);
			}
		}
		cout << DP[v] << endl;
	}
	return 0;
}