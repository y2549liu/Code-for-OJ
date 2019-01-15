#include <bits/stdc++.h>
using namespace std;

int main() {
	int m, n;
	cin >> m >> n;
	int q[31];
	for (int i = 0; i < n; ++i) {
		cout << "1\n";
		fflush(stdout);
		cin >> q[i]; //1 Õæ £»-1 ¼Ù
		if (q[i] == 0)
			exit(0);
	}
	int l = 1, r = m, mid;
	int flag;
	int round = 0;

	while (l <= r) {
		mid = (l + r) >> 1;
		cout << mid << endl;
		fflush(stdout);
		cin >> flag;
		flag *= q[round];
		if (flag == 0)
			exit(0);
		else if (flag == 1) 
			l = mid + 1;
		else 
			r = mid - 1;
		++round;
		if (round == n)
			round = 0;
	}
	return 0;
}