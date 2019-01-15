#include <bits/stdc++.h>
using namespace std;

struct rel {
	int time, loc;
	bool operator >(const rel &x) const {
		return time > x.time;
	}
};
int main() {
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i) {
		priority_queue<int, vector<int>, greater<int>> mem;
		priority_queue<rel, vector<rel>, greater<rel>> releaseTime;
		printf("Case #%d:\n", i);
		int n, m,start,duration;
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; ++i)
			mem.push(i);
		for (int i = 0; i < m; ++i) {
			scanf("%d %d", &start, &duration);
			//check if there is memory released;
			while (releaseTime.size() && start >= releaseTime.top().time ) {
				mem.push(releaseTime.top().loc);
				releaseTime.pop();
			}
			if (mem.size()) {
				printf("%d\n", mem.top());
				releaseTime.push({ start + duration,mem.top() });
				mem.pop();
			}
			else
				printf("no space left\n");
		}
	}
	return 0;
}