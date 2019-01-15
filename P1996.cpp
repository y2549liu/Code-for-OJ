#include<bits/stdc++.h>
using namespace std;
int main() {
	vector<int> v;
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		v.push_back(i);
	int now = 0;
	for (int i = n; i >= 1;--i) {
		now = (now + m - 1) % i;
		cout << v[now] << ' ';
		v.erase(v.begin() + now);
	}
	return 0;
}