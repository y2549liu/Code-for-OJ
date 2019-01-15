#include<bits/stdc++.h>
using namespace std;
int main() {
	int n, m;
	map<int, int> food;
	cin >> n >> m;
	int t;
	for (int i = 0; i < m; ++i){
		cin >> t;
		++food[t];
	}
	int ans = 100;
	while (ans) {
		int tot = 0;
		for (auto i : food) {
			tot += int(i.second/ans);
		}
		if (tot >= n)
			break;
		--ans;
	}
	cout << ans;
	return 0;
}