#include <bits/stdc++.h>
using namespace std;
int asc[101] = { 0x7fffffff }, h[101], n;
int ascl[101], descl[101];
int main() {
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> h[i];

	//calculus the maximun ascending sublist
	int maxl = 1, *loc;
	for (int i = 0; i < n; ++i) {
		loc = lower_bound(asc, asc + maxl, h[i]);
		if (loc == asc + maxl)
			++maxl;
		*loc = h[i];
		ascl[i] = maxl;
	}
	//calculus the maximun descending sublist
	/* reset */
	maxl = 1;
	memset(asc, 0, sizeof(asc));
	asc[0] = 0x7fffffff;
	/* end of reset */
	for (int i = n - 1; i >= 0; --i) {
		loc = lower_bound(asc, asc + maxl, h[i]);
		if (loc == asc + maxl)
			++maxl;
		*loc = h[i];
		descl[i] = maxl;
	}
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		ans = max(ans, ascl[i] + descl[i]);
	}
	cout << n - ans + 1;
	return 0;
}