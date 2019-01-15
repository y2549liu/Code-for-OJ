#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 65000;
int p[maxn],cnt=0;
bool notPrime[maxn] = { 1,1 };
void seive() {
	for (int i = 2; i < maxn; ++i) {
		if (!notPrime[i])
			p[cnt++] = i;
		for (int j = 0; j < cnt && i* p[j] < maxn; ++j) {
			notPrime[i*p[j]] = 1;
			if (i%p[j] == 0)
				break;
		}
	}
}

int main() {
	seive();
	ll t,n;
	cin >> t;
	while (t--) {
		cin >> n;
		for (ll i = n; true; ++i) {
			bool isPrime = 1;
			ll maxPrime = ll(sqrt(i));
			for (int j = 0; j < cnt && p[j]<=maxPrime; ++j) {
				if (i%p[j] == 0) {
					isPrime = 0;
					break;
				}
			}
			if (isPrime)
			{
				cout << i << endl;
				break;
			}
		}
	}
	return 0;
}