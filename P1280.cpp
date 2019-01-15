#include <bits/stdc++.h>
using namespace std;
struct task {
	int beg, end;
	bool operator<(const task &x) const {
		return (beg < x.beg);
	}
};
int dp[10001];
int main() {
	int n, k,start,duration;
	cin >> n >> k;
	priority_queue<task> taskQ;
	while (k--) {
		cin >> start >> duration;
		taskQ.push({ start,start + duration });
	}
	for (int i = n; i >= 1; --i) {
		if (taskQ.empty() || taskQ.top().beg != i) {
			dp[i] = dp[i + 1] + 1;
			continue;
		}
		while (taskQ.size() && taskQ.top().beg == i) {
			dp[i] = max(dp[i],dp[taskQ.top().end]);
			taskQ.pop();
		}
	}
	cout << dp[1];
	return 0;
}