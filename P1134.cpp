#include <bits/stdc++.h>
using namespace std;
int main() {
	int n,ans=1; cin >> n;
	int a[5] = { 1,1,2,1,4 }, b[4] = { 1,3,9,27 };
	while (n) {
		int r = n % 5;
		n /= 5;
		ans *= b[n%4];
		ans *= (n & 1) ? 4 : 1;
		ans *= a[r];
		ans %= 5;
	}
	cout << ((ans&1) ? (ans+5):ans);
	return 0;
}