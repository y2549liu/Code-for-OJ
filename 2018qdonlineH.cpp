#include <bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin >> t;
	while (t--) {
		string tfl;
		cin >> tfl;
		int n = tfl.length();
		long long ans = (long long)n*(n + 1)*(n + 2) / 6;
		for (int i = 0; i < n; ++i) {
			if (tfl[i] == '0')
				ans += n - i;
			if (i && tfl[i - 1] == tfl[i]) 
				ans += (long long)i* (n - i);
		}
		cout << ans << endl;
	}
	return 0;
}