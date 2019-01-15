#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int main() {
	LL n,x,y;int q;
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> q;
	while (q--) {
		cin >> x >> y;
		if ((x + y) & 1) {
			if (x & 1)
				cout << (x - 1) / 2 * n + (y / 2) + ((n*n + 1) / 2) << endl;
			else
				cout << (x - 2) / 2 * n + (n) / 2 + ((y + 1) / 2) + ((n*n+1) / 2) << endl;
		}
		else {
			if (x & 1)
				cout << (x - 1) / 2 * n + ((y + 1) / 2) << endl;
			else
				cout << (x - 2) / 2 * n + (n + 1) / 2 + (y / 2) << endl;
		}
	}
	return 0;
}