#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
	LL n, k;
	cin >> n >> k;
	LL end = min(n, (k-1) / 2);
	LL start = max((k - n), 1LL);
	cout << max(0LL, end - start + 1);
	return 0;
}