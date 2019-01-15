#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

long long popcount(long long x) {
	long long ans = 0;
	while (x) {
		if (x & 1)
			++ans;
		x >>= 1;
	}
	return ans;
}

long long lowbit(long long x) {
	return x&-x;
}
int main() {
	long long n, k,ans=0;
	cin >> n >> k;
	while (popcount(n) > k) {
		ans += lowbit(n);
		n += lowbit(n);
	}
	cout << ans;
	return 0;
}