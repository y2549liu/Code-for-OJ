#include <unordered_map>
#include <bits/stdc++.h>
#include <numeric>
using namespace std;

const int maxn = 15000001;
bool notPrime[maxn] = { 1,1,0 };
int Prime[10000], cnt=0, num[300001];

void init() {
	for (int i = 2; i < 3872; ++i) {
		if (!notPrime[i]) {
			Prime[cnt++] = i;
			for (int j = i<<1; j < maxn; j += i) 
				notPrime[j] = 1;
		}
	}
}
int gcd(int a, int b) {
	return (b == 0)? a: gcd(b, a%b);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	init();
	int n, t; cin >> n; 
	unordered_map<int, int> appear;
	int g=0, ans = n;
	for (int i = 0; i < n; ++i) {
		cin >> num[i];
		g = gcd(num[i], g);
	}
	unordered_map<int, int> input;
	for (int i = 0; i < n; ++i)
		++input[num[i] / g];
	for (auto Pair: input) {
		t = Pair.first;
		for (int j = 0; j < cnt && Prime[j]* Prime[j] <= t && t>1; ++j) {
			// it might be a prime number
			if (!notPrime[t]) {
				appear[t] += Pair.second;
				t = 1;
			}
			else if (t%Prime[j] == 0) {
				do {
					t /= Prime[j];
				}while (t%Prime[j] == 0);
				appear[Prime[j]] += Pair.second;
			}
		}
		if (t > 1) 
			appear[t] += Pair.second;
	}
	for (auto p : appear) 
		ans = min(ans, n - p.second);
	if (ans == n)
		cout << "-1";
	else
		cout << ans;
	return 0;
}