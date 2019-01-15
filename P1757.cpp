#include <bits/stdc++.h>
using namespace std;

struct obj {
	int weight, price;
};
vector<obj> arr[101];

int dpformer[1001];
int dpcurrent[1001];
int main() {
	int n, m;
	cin >> m >> n;
	int w, p, g;
	for (int i = 0; i < n; ++i) {
		cin >> w >> p >> g;
		arr[g].push_back({ w,p });
	}
	for (int i = 1; i <= 100;++i) {
		for (auto j : arr[i]) {
			for (int k = m; k >= j.weight; --k) {
				dpcurrent[k] = max(dpcurrent[k], dpformer[k - j.weight] + j.price);
			}
		}
		memcpy(dpformer, dpcurrent, sizeof(dpcurrent));
	}
	cout << dpcurrent[m];
	return 0;
}