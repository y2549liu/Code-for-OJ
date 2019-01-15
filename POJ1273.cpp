#include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <cmath>
#include <string>
using namespace std;

int n, m, G[201][201];
int augment() {
	int ans = 0, now, minflow=0x7fffffff, visited[201] = { 0 }, prev[201] = { 0 };
	visited[1] = 1;
	deque<int> Q;
	Q.push_back(1);
	while (Q.size()) {
		now = Q.front();
		Q.pop_front();
		for (int i = 1; i <= n; ++i) {
			if (visited[i] || !G[now][i]) 
				continue;
			prev[i] = now;
			if (i == n) {
				Q.clear();
				now = n;
				break;
			}
			visited[i] = 1;
			Q.push_back(i);
		}
	}
	if (now != n)
		return 0;
	while (prev[now]) {
		minflow = min(minflow, G[prev[now]][now]);
		now = prev[now];
	}
	now = n;
	while (prev[now]) {
		G[prev[now]][now] -= minflow;
		G[now][prev[now]] += minflow;
		now = prev[now];
	}
	return minflow;
}
int main() {
	while (cin >> m >> n) {
		memset(G, 0, sizeof(G));
		int src, des, cap, ans = 0, flow = 0;
		for (int i = 1; i <= m; ++i) {
			cin >> src >> des >> cap;
			G[src][des] += cap;
		}	
		while (flow = augment()) 
			ans += flow;
		cout << ans<< endl;
	}
	return 0;
}