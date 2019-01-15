#include <bits/stdc++.h>
using namespace std;
struct cmp {
	template<typename T>
	bool operator()(const T& a, const T& b) {
		return (a.first > b.first);
	}
};
int main() {
	ios::sync_with_stdio(false);
	int n, m, price, amount,tot=0;
	cin >> n >> m;
	priority_queue<pair<int, int>, vector<pair<int,int>>, cmp> Q;
	for (int i = 0; i < m; ++i) {
		cin >> price >> amount;
		Q.push(make_pair(price, amount));
	}
	while (n) {
		if (n > Q.top().second) {
			n -= Q.top().second;
			tot += Q.top().second * Q.top().first;
			Q.pop();
		}
		else {
			tot += n * Q.top().first;
			n = 0;
		}
	}
	cout << tot;
	return 0;
}