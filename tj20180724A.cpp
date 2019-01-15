#include <bits/stdc++.h>
using namespace std;


int main() {
	int n;
	while (cin >> n &&n) {
		int ans = 0, num[1001], sum[1001], end[1001];
		memset(num, 0, sizeof(num));
		memset(sum, 0, sizeof(sum));
		memset(end, 0, sizeof(end));
		for (int i = 1; i <= n; ++i) {
			cin >> num[i];
			sum[i] = num[i];
			end[i] = i;
			for (int j = 1; j < i; ++j) {
				if (num[i] > num[end[j]] && sum[j]+num[i]>sum[i]) {
					sum[i] = sum[j] + num[i];
					end[i] = i;
				}
			}
			ans = max(ans, sum[i]);
		}
		cout << ans << endl;
	}
	return 0;
}