#include <bits/stdc++.h>
using namespace std;
typedef int64_t LL;
const LL p = 998244353;
const int times = 100;

map<LL, int> divisor;
vector<int> prime{ 2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,998244353,1000000007,1000000007 };

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

inline LL q_mul(LL a, LL b, const LL &n){
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
	for (auto i : prime) {
		if (n%i == 0)
			return (n == i);
	}
	for (int i = 0; i < times; ++i) {
		LL a = rand(n - 2) + 1;
		if (!witness(a,n))
			return (0);
	}
	return (1);
}

inline LL f(const LL &a, const LL &n, const LL &c) {
	return move( (q_mul(a, a, n) + c) % n );
}

inline LL pollard_rho(LL n, LL c) {//floyd ”≈ªØ
	LL x, y, p;
	y = x = rand(n - 2) + 1;
	do {
		x = f(x, n, c);
		y = f(f(y, n, c), n, c);
		p = gcd(n, abs(x - y));
		if (p > 1)
			return p;
	} while (x != y);
	return n;
}

void find(LL n){
	if (n == 1)
		return;
	for (auto i : prime) {
		if (n == i) {
			++divisor[n];
			return;
		}
		else if (n % i == 0) {
			++divisor[i];
			find(n / i);
			return;
		}
	}
	if (miller_rabin(n)) {
		++divisor[n];
		return;
	}
	int factor = n;
	while (factor==n) {
		factor = pollard_rho(n, rand()%n);
	}
	find(factor);
	find(n / factor);
	return;
}

inline LL c(LL a, LL b, LL n) { //a»°b mode n
	LL result = 1, inverse ,tmp;;
	for (int i = 0; i < b; i++) {
		result = q_mul(result, a - i, n);
	}
	for (int i = 2; i <= b; i++) {
		ext_gcd(i, n, inverse, tmp);
		inverse %= n;
		if (inverse < 0) inverse += n;
		result = q_mul(result, inverse, n);
	}
	return result;
}

int main(){
	LL n, k ,result=1;
	cin >> n >>k;
	find(n);
	if (n == 1)
		cout << 1;
	else {
		for (auto i : divisor) {
			result = q_mul(result, c(i.second + k + 1, i.second, p), p);
		}
		cout << result;
	}
	return 0;
}