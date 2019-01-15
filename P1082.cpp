#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL extGcd(LL a,LL b,LL &x,LL &y) {
	if (b == 0) {
		x = 1; y = 0;
		return a;
	}
	else {
		LL r = extGcd(b, a%b, y, x);
		y = y - int(a / b)*x;
		return r;
	}
}

int main() {
	LL a, b, x, y;
	cin >> a >> b;
	LL r = extGcd(a, b, x, y);
	cout << ((x%b) + b) % b<<endl;
	return 0;
}