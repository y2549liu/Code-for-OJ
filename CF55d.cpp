#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 2520;
//          digit	hashed lcm		remainder of 2520
long long dp[20]	[49]			[maxn+1];
// the lcm of elements in {1,2,3,4,5,6,7,8,9} only has 48 different value, so hash is useful
int HASH[maxn+1];
// store the digits of the upperbound
int n[20];

LL GCD(LL a, LL b) {
	return b ? GCD(b, a%b) : a;
}
LL LCM(LL a, LL b) {
	return a*b / GCD(a, b);
}

LL dfs(int len,		// the remain digits need to be placed		
	int lcm,		// the least common muliply of the former digits
	int rmd,		// the remainder of the former number mod 2520
	bool upbound)	// whether the next digit has an upperbound
{
	if (len == 0)
		return (rmd%lcm) == 0;
	else if (!upbound && dp[len][HASH[lcm]][rmd]!=-1)
		return dp[len][HASH[lcm]][rmd];
	LL ans = 0;
	int end = upbound ? n[len]:9;
	for (int i = 0; i <= end; ++i) 
		ans += dfs(len - 1, i ? LCM(lcm, i) : lcm, (rmd * 10 + i) % maxn, upbound && (i == end));
	if (!upbound)
		dp[len][HASH[lcm]][rmd] = ans;
	return ans;
}
void init() {
	memset(dp, -1, sizeof(dp));
	for (int i = 1,cnt = -1; i <= sqrt(maxn); i++) 
		if (maxn % i == 0) 
			HASH[i] = ++cnt, HASH[maxn / i] = ++cnt;
}
LL count(LL r) {
	int cnt = 0;
	while (r) {
		n[++cnt] = r % 10;
		r /= 10;
	}
	return dfs(cnt, 1, 0, 1);
}
int main() {
	init();
	int t;
	LL l, r;
	cin >> t;
	while (t--) {
		cin >> l >> r;
		cout << count(r) - count(l - 1) << endl;
	}
	return 0;
}
