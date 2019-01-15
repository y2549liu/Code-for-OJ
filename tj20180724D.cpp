#include <bits/stdc++.h>
using namespace std;
int invoice[31];
int dp[4000000];
int main() {
	int n,m;
	double q;
	while (cin >> q >> n && n) {
		q *= 100;
		int cnt = 0;
		memset(dp, 0, sizeof(dp));
		for (int i = 0; i < n; ++i) {
			cin >> m;
			bool flag=1;
			char type;
			double amount,va=0,vb=0,vc=0;
			for (int j = 0; j < m; ++j) {
				scanf(" %c:%lf", &type, &amount);
				if (!flag)
					continue;
				if (type == 'A')
					va += amount;
				else if (type == 'B')
					vb += amount;
				else if (type == 'C') {
					vc += amount;
				}
				else
					flag = 0;
			}
			if (va > 600 || vb > 600 || vc > 600 || va + vb + vc > 1000)
				flag = 0;
			if (flag)
				invoice[cnt++] = (va+vb+vc)*100;
		}
		for (int i = 0; i < cnt; ++i) {
			for (int j = q; j >= invoice[i]; --j) {
				dp[j] = max(dp[j], dp[j - invoice[i]] + invoice[i]);
			}
		}
		cout << setiosflags(ios::fixed) << setprecision(2) << dp[int(q)]/100.0 << endl;
	}
	return 0;
}