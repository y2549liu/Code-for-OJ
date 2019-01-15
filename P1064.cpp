#include <bits/stdc++.h>
using namespace std;
struct obj {
	int price, value, sub, subno[2], parent;
} object[61];
int dp[32001][60];
int main() {
	int money, n ,group=0;
	cin >> money >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> object[i].price >> object[i].value >> object[i].parent;
		object[i].value *= object[i].price;
		if (object[i].parent) {
			int pa = object[i].parent;
			object[pa].subno[object[pa].sub++] = i;
		}
	}
	for (int i = 1; i <= n; ++i) {
		if (object[i].parent)
			continue;
		++group;
		vector<pair<int, int>> v;
		v.push_back({ object[i].price, object[i].value });
		v.push_back({ 0,0 });
		if (object[i].sub > 0) {
			int sn1 = object[i].subno[0];
			v.push_back({ object[i].price + object[sn1].price,
				object[i].value + object[sn1].value });
			if (object[i].sub > 1) {
				int sn2 = object[i].subno[1];
				v.push_back({ object[i].price + object[sn2].price + object[sn1].price,
					object[i].value + object[sn2].value + object[sn1].value });
				v.push_back({ object[i].price + object[sn2].price,
					object[i].value + object[sn2].value });
			}
		}
		for (auto Obj : v) {
			for (int tot = money; tot >= Obj.first; --tot) {
				dp[tot][group] = max(dp[tot][group], dp[tot - Obj.first][group - 1] + Obj.second);
			}
		}
	}
	cout << dp[money][group];
	return 0;
}