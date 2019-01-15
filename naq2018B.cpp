#include <bits/stdc++.h>
using namespace std;

int main() {
	int p, q, r;
	cin >> p >> q >> r;
	if (p*q / __gcd(p, q) <= r)
		cout << "yes" << endl;
	else
		cout << "no" << endl;

	return 0;
}