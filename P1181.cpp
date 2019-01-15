#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	int n, m, sum=0, parts=1,tmp;
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> tmp;
		if (sum + tmp <= m) {
			sum += tmp;
		}
		else {
			sum = tmp;
			++parts;
		}
	}
	cout << parts ;
	return 0;
}