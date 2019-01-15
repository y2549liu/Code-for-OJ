#include<bits/stdc++.h>
using namespace std;
int a[100001],n,k;
int main() {
	cin >> n >> k;
	a[0] = 1;
	for (int i = 1; i <= n; ++i) {
		for (int step = 1; step <= k; ++step) {
			if (i >= step)
				a[i] += a[i-step];
		}
		a[i] %= 100003;
	}
	cout << a[n];
	return 0;
}