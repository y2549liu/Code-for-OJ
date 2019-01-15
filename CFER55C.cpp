#include<bits/stdc++.h>
using namespace std;
char buf[10000000];
const double eps = 1e-9;
int sgn(double a) { return a < -eps ? -1 : a < eps ? 0 : 1; }
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, len = 0, slen = 0, llen = 0, before = 0;
		double ratio = 1000000.0;
		scanf("%d", &n);
		map<int, int> cnt;
		for (int i = 0; i < n; ++i) {
			scanf("%d", &len);
			++cnt[len];
			if (cnt[len] >= 4) {
				slen = llen = len;
				cin.getline(buf, 1e7);
				break;
			}
		}
		if (slen) {
			printf("%d %d %d %d\n", slen, slen, llen, llen);
			continue;
		}
		for (auto pi : cnt) {
			if (pi.second < 2)
				continue;
			if (before) {
				if ( sgn(ratio*before-pi.first)==1) {
					ratio = double(pi.first) / before;
					slen = before;
					llen = pi.first;
					before = pi.first;
				}
			}
			else
				before = pi.first;
		}
		printf("%d %d %d %d\n", slen, slen, llen, llen);
	}
	return 0;
}