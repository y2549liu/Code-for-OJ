#include <bits/stdc++.h>
using namespace std;
const long long mod = 100000000;
struct matrix {
	long long a[2][2] = { 0,0,0,0 };
	matrix operator * (matrix m){
		matrix ans;
		for (long long j = 0; j < 2; ++j) {
			for (long long i = 0; i < 2; ++i) {
				for (long long k = 0; k < 2; ++k) {
					ans.a[i][k] = (ans.a[i][k] + a[i][j] * m.a[j][k])%mod;
				}
			}
		}
		return ans;
	}
	matrix exp(long long n) {
		matrix ans = {1,0,0,1},tmp=*this;
		while (n) {
			if (n & 1) 
				ans = ans * tmp;
			tmp = tmp * tmp;
			n >>= 1;
		}
		return ans;
	}
};
int main() {
	long long n, m; cin >> n >> m;
	n = __gcd(n, m);
	matrix coef = { 1,1,1,0 };
	coef = coef.exp(n);
	cout << coef.a[1][0];
	return 0;
}