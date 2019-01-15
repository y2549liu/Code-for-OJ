#include <bits/stdc++.h>
using namespace std;
long long k, n;
long long cal(long long n) {
	if (n>1)
		return (n & 1) + cal(n >> 1)*k;
	else
		return 1;
}
int main() {
	cin >> k >> n;
	cout << cal(n);
	return 0;
}