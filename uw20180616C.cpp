#include <bits/stdc++.h>
using namespace std;
int main() {
	int t,n;
	cin >> t;
	while (t--) {
		double r[8];
		cin >> n;
		for (int i = 0; i < n; ++i)
			cin >> r[i];
		sort(r, r + n);
		double ans = 1000000000000;
		do {
			double d[8],wid=0;//the distance from the left side to the centre of the ith circle
			memcpy(d, r, sizeof(r));
			for (int i = 0; i < n; ++i) {
				for (int j = i + 1; j < n; ++j) 
					d[j] = max(d[j], d[i] + 2.0 * sqrt(r[i] * r[j]));
				wid = max(wid, d[i] + r[i]);
			}
			ans = min(ans, wid);
		} while (next_permutation(r, r + n));
		cout.setf(ios::fixed);
		cout.precision(3);
		cout << setiosflags(ios::fixed) << setprecision(3)<< ans << endl;
	}
	return 0;
}