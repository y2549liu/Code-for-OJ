#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll count(ll x) {
	if (x < 10)
		return x;
	ll ans=0;
	while (x) {
		ans += x % 10;
		x /= 10;
	}
	return count(ans);
}

bool check(ll x) {
	ll cur = x*x;
	ll cmp = count(cur);
	for (ll i = 3; i <= 5; ++i) {
		if (cmp != count(cur*=x))
			return 0;
	}
	return 1;
}

int main() {
	int cnt = 0;
	for (ll i = 2; i <= 2018; ++i) {
		
		if (check(i)) {
			cout << i << " ";
			++cnt;
		}
	}
	cout << endl << "total:" << cnt;
	return 0;
}