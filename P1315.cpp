#include <bits/stdc++.h>
using namespace std;
struct stick {
	int w, d;
	bool operator<(const stick &x)const {
		return (w != x.w) ? (w>x.w):(d>x.d);
	}
}s[5001];
int n, w, d, lis[5001] = {0x80000000}, len = 0;
int main() {
	//freopen("P1233.in", "r", stdin);
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> s[i].w >> s[i].d;
	sort(s, s + n);
	for (int i = 0; i < n; ++i) 
		if (s[i].d > lis[len])
			lis[++len] = s[i].d;
		else 
			*lower_bound(lis + 1, lis + len + 1, s[i].d) = s[i].d;
	cout << len;
	return 0;
}