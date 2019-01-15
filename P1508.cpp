#include <bits/stdc++.h>
using namespace std;

int food[202][202], energy[202][202];
template<class T>
T Max(const T &a1, const T &a2, const T &a3) {
	return max(a1, max(a2, a3));
}
template<class T>
T Max(const T &a1, const T &a2, const T &a3, const T &a4) {
	return max(max(a1, a4), max(a2, a3));
}
int main() {
	int m, n;
	cin >> m >> n;
	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> food[i][j];
		}
	}
	//begin with line m+1, row n/2;
	for (int i = 0; i <= m+1; ++i) {
		for (int j = 0; j <= n+1; ++j) {
			energy[i][j]= -100000000;
		}
	}
	energy[m + 1][(n + 1) / 2] = 0;
	int ans = -100000000;
	for (int i = m; i >=1; --i) {
		for (int j = 1; j <= n; ++j) {
			energy[i][j] = food[i][j] + Max(energy[i + 1][j - 1], energy[i + 1][j], energy[i + 1][j + 1]);
		}
	}
	for (int j = 1; j <= n; ++j) {
		ans=max(ans,energy[1][j]);
	}
	cout << ans;
	return 0;
}