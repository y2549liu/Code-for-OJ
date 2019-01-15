#include <bits/stdc++.h>
using namespace std;
int DP[10000];

int main() {
	ios::sync_with_stdio(false);
	int T, w1, w2, netweight, n;
	cin >> T;
	while (T--) {
		cin >> w1 >> w2 >> n;
		memset(DP, 0x7f, sizeof(DP));
		DP[0] = 0;
		netweight = w2 - w1;
		int weight, value;
		for (int i = 0; i < n; ++i) {
			cin >> value >> weight;
			for (int j = weight; j <= netweight; ++j) {
				DP[j] = min(DP[j], DP[j - weight] + value);
			}
		}
		if (DP[netweight] == 0x7f7f7f7f)
			printf("This is impossible.\n");
		else
			printf("The minimum amount of money in the piggy-bank is %d.\n", DP[netweight]);
	}
	return 0;
}