#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
struct env {
	LL w, h, no;
	bool operator<(const env &x)const {
		return w*h < x.w*x.h;
	}
	bool operator>(const env &x)const {
		return (w>x.w && h>x.h);
	}
};

int dp[5000][2];
int main() {
	int n, w, h;
	cin >> n >> w >> h;
	env now = { w,h,0};
	vector<env> ev;
	ev.push_back(now);
	for (int i = 1; i <= n; ++i) {
		cin >> w >> h;
		ev.push_back({ w,h,i });
	}
	sort(ev.begin()+1, ev.end());
	int ans[2] = { 0,0 };
	for (int i = 1; i <= n; ++i) {
		if (ev[i] > ev[0])
			dp[i][0] = 1, dp[i][1] = 0;
		else
			continue;
 		for (int j = 1; j < i; ++j) {
			if (dp[j][0] && ev[i] > ev[j] && dp[j][0] + 1> dp[i][0]) {
				dp[i][0] = dp[j][0] + 1;
				dp[i][1] = j;
			}
		}
		if (dp[i][0] > ans[0]) {
			ans[0] = dp[i][0];
			ans[1] = i;
		}
	}
	cout << ans[0] << endl;
	int nowe = ans[1];
	vector<int> v;
	while (nowe) {
		v.push_back(ev[nowe].no);
		nowe = dp[nowe][1];
	}
	for (auto iter = v.rbegin();iter!=v.rend();++iter)
		cout << *iter << " ";
	return 0;
}