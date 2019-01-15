#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 500001;
LL num[maxn],sum[maxn];
int n,m;
int lowbit(int x) {
	return (x&-x);
}
LL quest(int l) {
	LL ans = 0;
	while (l) {
		ans += sum[l];
		l -= lowbit(l);
	}
	return ans;
}
void update(int l, int x) {
	while (l<=n) {
		sum[l] += x;
		l += lowbit(l);
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin >> n >>m;
	for (int i = 1; i <= n; ++i) {
		cin >> num[i];
		update(i, num[i]);
	}
	int act, x, y;
	for (int i = 1; i <= m; ++i) {
		cin >> act >> x >> y;
		if (act == 1)
			update(x, y);
		else
			cout << quest(y) - quest(x - 1)<<endl;
	}
	return 0;
}