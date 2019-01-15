#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int n, q, a[200001], zeros=0;
vector<int> loc[200001],undone;
void EXIT(bool flag) {
	string ans[2] = { "NO\n","YES\n" };
	cout << ans[flag];
	if (flag) {
		int i = 1;
		while (a[i] == 0 && i<n) ++i;
		for (int j = 1; j < i; ++j)
			a[j] = a[i];
		for (int j = i + 1; j <= n; ++j)
			if (!a[j])
				a[j] = a[j - 1];
		for (int j = 1; j <= n; ++j)
			cout << a[j] << " ";
	}
	exit(0);
}
void change_range(int l, int r, int val) {
	auto it1 = lower_bound(undone.begin(), undone.end(), l), it2 = upper_bound(undone.begin(), undone.end(), r);
	if (it2 - it1 == loc[val].size())
		undone.erase(it1, it2);
	else if (it2 - it1 > loc[val].size())
		EXIT(0);
	else
		cout << "error\n";
}
int main() {
	ios::sync_with_stdio(0);	cin.tie(0);
	cin >> n >> q;
	int hasq = 0;
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		if (a[i] > q)
			EXIT(0);
		else if (a[i] == q)
			hasq = 1;
		else if (a[i] == 0)
			++zeros;
	}
	if (!hasq) {
		if (!zeros) 
			EXIT(0);
		else
			*(find(a + 1, a + n + 1, 0)) = q;
	}
	for (int i = 1; i <= n; ++i)
	{
		if (a[i]) {
			loc[a[i]].push_back(i);
			undone.push_back(i);
		}
	}
	for (int i = q; i > 1; --i) {
		if (loc[i].size())
			change_range(*(loc[i].begin()), *(loc[i].end()-1), i);
	}
	change_range(1, n, 1);
	EXIT(1);
	return 0;
}