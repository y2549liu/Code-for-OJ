/* https://www.luogu.org/problemnew/show/P4752 */
#include <bits/stdc++.h>
using namespace std;


typedef int64_t LL;
const LL p = 998244353;
const int TIMES = 100;

map<LL, int> divisor;
vector<int> PRIMENUMBER{ 2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,998244353,1000000007,1000000007 };

inline LL rand(const LL &n) {
	return (LL((double)rand() / RAND_MAX * n + 0.5));
}

inline LL gcd(LL a, LL b) {
	if (b > a)
		swap(a, b);
	if (b == 0)
		return move(a);
	return gcd(b, a%b);
}

inline LL ext_gcd(LL a, LL b, LL &x, LL &y) {
	if (b == 0)
		return (x = 1, y = 0, a);
	LL ans = ext_gcd(b, a%b, y, x);
	y -= (a / b) * x;
	return move(ans);
}

inline LL q_mul(LL a, LL b, const LL &n) {
	LL ans = 0;
	while (b)
	{
		if (b & 1)
			ans += a;
		a = (a << 1) % n;
		b >>= 1;
	}
	return move(ans %= n);
}

inline LL q_pow(LL a, LL exp, const LL &n) {
	LL ans = 1;
	while (exp) {
		if (exp & 1)
			ans = q_mul(ans, a, n);
		exp >>= 1;
		a = q_mul(a, a, n);
	}
	return move(ans %= n);
}

inline bool witness(LL a, const LL &n) {
	LL exp = n - 1;
	int cnt = 0;
	while (!(exp & 1)) {
		exp >>= 1;
		++cnt;
	}
	LL result = q_pow(a, exp, n);
	if (result == 1 || result == n - 1)
		return (1);
	while (--cnt >= 0) {
		result = q_mul(result, result, n);
		if (result == n - 1)
			return (1);
	}
	return (0);
}

inline bool miller_rabin(LL n) {
	if (n < 2)
		return (0);
	for (auto i : PRIMENUMBER) {
		if (n%i == 0)
			return (n == i);
	}
	for (int i = 0; i < TIMES; ++i) {
		LL a = rand(n - 2) + 1;
		if (!witness(a, n))
			return (0);
	}
	return (1);
}
bool IsPrime(long long x) {
	return miller_rabin(x);
}

int main() {
	ios::sync_with_stdio(false);
	int t, n, m;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		map<long long, int> A;
		long long tmp;
		for (int i = 0; i < n; ++i) {
			cin >> tmp;
			++A[tmp];
		}
		for (int i = 0; i < m; ++i) {
			cin >> tmp;
			--A[tmp];
		}
		int cnt = 0;
		for (auto v : A) {
			if (v.second == 0 || v.first == 1)
				continue;
			else if (v.second > 1){
				cnt = 2; 
				break;
			}
			else if (cnt || !IsPrime(v.first)) {
				cnt = 2;
				break;
			}
			else {
				++cnt;
				if (cnt > 1)
					break;
			}
		}
		if (cnt > 1 || cnt == 0)
			cout << "NO\n";
		else
			cout << "YES\n";
	}
	return 0;
}