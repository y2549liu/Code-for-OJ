#include <bits/stdc++.h>
using namespace std;
const int maxn = 10000001;
bool isPrime[maxn];
int n,m,t;
void init() {
	memset(isPrime + 2, 1, sizeof(isPrime));
	for (int i = 2; i <= sqrt(n); ++i) {
		if (!isPrime[i])
			continue;
		for (int j = i*i; j <= n; j += i) {
			isPrime[j] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	init();
	string ans[2] = { "No\n","Yes\n" };
	while (m--) {
		cin >> t;
		cout << ans[isPrime[t]];
	}
	return 0;
}