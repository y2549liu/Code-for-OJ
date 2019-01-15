#include <bits/stdc++.h>
using namespace std;


int main() {
	int n, h, a, b, k, ta, tb, fa, fb;
	cin >> n >> h >> a >> b >> k;
	for (int i = 0; i < k; ++i) {
		cin >> ta >> fa >> tb >> fb;
		if (ta == tb)
			cout << abs(fa - fb);
		else {
			if (fa > b && fb > b)
				cout << abs(ta - tb) + abs(fa + fb - 2 * b);
			else if (fa < a && fb < a)
				cout << abs(ta - tb) + abs(fa + fb - 2 * a);
			else
				cout << abs(ta - tb) + abs(fa - fb);
		}
		cout << endl;
	}
	return 0;
}