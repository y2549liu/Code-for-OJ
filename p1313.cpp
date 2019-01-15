#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 10007;
ll fpow(ll x, int n) {
	ll ans = 1;
	x %= mod;
	while (n) {
		if (n & 1)
			ans = (x*ans)%mod;
		x =(x*x)%mod;
		n >>= 1;
	}
	return ans;
}
ll c[1001][1001] = { 0 };
ll dfs(int m,int n) {
	if (n >= (m >> 1)) n = m - n;
	if (c[m][n])
		return c[m][n];
	else if (n == 0)
		return c[m][n] = 1;
	else if (n == 1)
		return c[m][n] = m;
	else
		return c[m][n] = (dfs(m - 1,n) + dfs(m - 1,n - 1))%mod;
}

int main() {
	ll a, b, k, n, m, ans = 1;
	cin >> a >> b >> k >> n >> m;
	if (n + m == k) {
		int ans = fpow(a, n)*fpow(b, m);
		ans %= mod;
		ans = (ans * dfs(k, m))%mod;
		cout << ans;
	}
	else cout << 0;
	return 0;
}