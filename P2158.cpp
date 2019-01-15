#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 40001;
int p[maxn];

void phi(int n){
	for (int i = 1; i <= n; ++i)
		p[i] = i;
	for (int i = 2; i <= n; i += 2)
		p[i] >>= 1;
	for (int i = 3; i <= n; i+=2) {
		if (p[i]==i)
			for (int j = i; j <= n; j += i)
				p[j] = (p[j] / i)*(i - 1);
	}
}
int main() {
	int n;LL ans = 0;
	cin >> n;
	phi(n);
	for (int i = 1; i < n; ++i) //0-n-1
		ans += p[i];
	cout << (ans<<1)+(n>1);
	return 0;
}