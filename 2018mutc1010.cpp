#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct vec {
	int val[5], size;
	bool operator<(const vec& x) const {
		for (int i = 0; i < size; ++i) 
			if (val[i] != x.val[i])
				return val[i] < x.val[i];
		return false;
	}
	ll operator*(const vec& x) {
		ll ans = 0;
		for (int i = 0; i < size; ++i) 
			ans += val[i] * x.val[i];
		return ans;
	}
	vec inv() const {
		vec ans;
		ans.size = size;
		for (int i = 0; i < size; ++i)
			ans.val[i] = -val[i];
		return ans;
	}
};

int main() {
	int t,m,n,k;
	cin >> t;
	while (t--) {
		cin >> n >> m >> k;
		map<vec,ll> mp1,mp2;
		for (int i = 0; i < 2 << k; ++i) {
			vec coef; coef.size = k;
			int cnt = 0;
			do
				coef.val[cnt++] = (i & 1) ? 1 : -1;
			while (i <<= 1);
			mp1[coef] = -0x7fffffff; mp2[coef] = -0x7fffffff;
		}
		vec skill; int comp;
		for (int i = 1; i <= n; ++i) {
			cin >> comp;
			for (int i = 0; i < k; ++i)
				cin >> skill.val[i];
			skill.size = k;
			for (int i = 0; i < 2 << k; ++i) {
				vec coef;coef.size = k;
				int cnt = 0;
				do
					coef.val[cnt++] = (i & 1) ? 1 : -1;
				while (i <<= 1);
				mp1[coef] = max(mp1[coef], coef*skill + comp);
			}
		}
		for (int i = 1; i <= m; ++i) {
			cin >> comp;
			for (int i = 0; i < k; ++i)
				cin >> skill.val[i];
			skill.size = k;
			for (int i = 0; i < 2 << k; ++i) {
				vec coef; coef.size = k;
				int cnt = 0;
				do
					coef.val[cnt++] = (i & 1) ? 1 : -1;
				while (i <<= 1);
				mp2[coef] = max(mp1[coef], coef*skill + comp);
			}
		}
		ll ans = -0x7fffffff;
		for (int i = 0; i < 2 << k; ++i) {
			vec coef; coef.size = k;
			int cnt = 0;
			do
				coef.val[cnt++] = (i & 1) ? 1 : -1;
			while (i <<= 1);
			ans = max(ans, mp1[coef] + mp2[coef.inv()]);
		}
		cout << ans << endl;
	}
	return 0;
}