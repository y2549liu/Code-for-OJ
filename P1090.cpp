/* https://www.luogu.org/problemnew/show/P1090 */
#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	int n, tot=0 ,tmp;
	cin >> n;
	priority_queue<int,vector<int>,greater<int>> Q;
	for (int i = 0; i < n; ++i) {
		cin >> tmp;
		Q.push(tmp);
	}
	for (int i = 1; i < n; ++i) {
		tmp = Q.top();
		Q.pop();
		tmp += Q.top();
		Q.pop();
		tot += tmp;
		Q.push(tmp);
	}
	cout << tot;
	return 0;
}
