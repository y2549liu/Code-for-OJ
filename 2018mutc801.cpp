#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5;

typedef long long LL;
LL PrefixMul[maxn+1], PrefixInvMul[maxn+1];
const LL mod = 998244353;
LL qPow(LL x, int exp) {
	if (exp == 1)
		return x;
	LL ans = (qPow(x, exp >> 1))%mod;
	ans = (ans*ans) % mod;
	if (exp & 1)
		ans = (ans*x) % mod;
	return ans;
}
LL inv(LL x) {
	return qPow(x, mod - 2);
}
void init() {
	PrefixMul[0] = 1;
	for (int i = 1; i <= maxn; ++i)
		PrefixMul[i] = (PrefixMul[i - 1] * i) % mod;
	PrefixInvMul[maxn] = inv(PrefixMul[maxn]);
	for(int i = maxn - 1; i >= 0; --i) 
		PrefixInvMul[i] = (PrefixInvMul[i + 1] * (i + 1)) % mod;
}

LL c(int m, int n) {
	return ((PrefixMul[m] * PrefixInvMul[n]) % mod * PrefixInvMul[m - n]) % mod;
}

int main() {
	int t,n,m,k;
	init();
	cin >> t;
	while (t--) {
		//nÇò m¿ò Ã¿¿ò<kÇò
		cin >> k >> m >> n;
		LL ans = 0;
		for (int i = 0; i <= m; ++i) {
			int j = n - i*k;
			if (j < 0) break;
			ans += c(m, i)*c(m + j - 1, j)*((i & 1) ? -1 : 1);
			ans %= mod;
		}
		cout << (ans + mod) % mod << endl;
	}
	return 0;
}