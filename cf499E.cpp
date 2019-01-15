#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
	if (a < b)
		swap(a, b);
	if (b == 0)
		return a;
	return gcd(b, a%b);
}

int main() {
	int n, k, num[100001], tmp; 
	cin >> n >> k;
	int maxdiv = k;
	for (int i = 1; i <= n; ++i) {
		cin >> tmp;
		maxdiv = gcd(maxdiv, tmp);
		if (maxdiv == 1)
			break;
	}
	cout << k / maxdiv<<endl;
	for (int i = 0; i < k; i += maxdiv)
		cout << i << " ";
	return 0;
}