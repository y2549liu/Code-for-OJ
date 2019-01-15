#include <bits/stdc++.h>
using namespace std;
const int maxn = 101;
struct tvprogramme {
	int s, e;
	bool operator <(const tvprogramme &x) const {
		//开始晚的优先，结束早的优先
		return (s != x.s)?(s>x.s):(e<x.e);
	}
}p[maxn];
int main() {
	int n;
	while (cin >> n && n) {
		for (int i = 0; i < n; ++i) 
			cin >> p[i].s >> p[i].e;
		sort(p, p + n);
		int now=0x7fffffff,cnt=0;
		for (int i = 0; i < n; ++i) {
			if (p[i].e <= now) {
				++cnt;
				now = p[i].s;
			}
		}
		cout << cnt << endl;
	}
	return 0;
}