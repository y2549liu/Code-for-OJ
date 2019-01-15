#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,a,b,ans=0; cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a >> b;
		ans = max(ans, a + b);
	}
	cout << ans;
	return 0;
}