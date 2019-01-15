#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ll n,m;
	cin >> n >> m;
	if (n > m)
		swap(n, m);
	ll ans = n*m / 2;
	if (n == 1 && (m + 1) % 6 / 3)
		--ans;
	else if (n == 2) {
		if (m == 2)
			ans -= 2;
		else if (m == 3 || m == 7)
			ans -= 1;
	}
	cout << 2*ans;
	return 0;
}