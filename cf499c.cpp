#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, m, tmp;
	cin >> n >> m;
	double w = m;
	for (int i = 1; i <= 2 * n; ++i) {
		cin >> tmp;
		if (tmp <= 1) {
			cout << "-1";
			return 0;
		}
		w = w*tmp / (tmp - 1);
	}
	cout << setprecision(10) <<w - m;
	return 0;
}