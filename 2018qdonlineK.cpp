#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,t;
	cin >> t;
	while (t--) {
		cin >> n;
		int x, s[32] = { 0 },ans = 0;
		for (int i = 0; i < n; ++i) {
			cin >> x;
			++s[int(log2(x))];
		}
		for (int i = 0; i < 32; ++i) 
			ans = max(ans, s[i]);
		cout << ans << endl;
	}
	return 0;
}