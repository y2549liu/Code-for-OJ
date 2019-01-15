//ÍøÂçÁ÷ dinic
#include <bits/stdc++.h>
using namespace std;
const int INF = 0x7fffffff;
int n, m, s, t;
struct edge {
	int src, des, vol;
}E[200001];
struct node {
	vector<int> e;
	int layer;
}N[10001];
int bfs() {
	for (int i = 1; i <= n; ++i)
		N[i].layer = INF;
	N[s].layer = 1;
	deque<int> Q;
	Q.push_back(s);
	while (Q.size()) {
		int now = Q.front(); Q.pop_front();
		if (now == t)
			return N[now].layer;
		for (auto e : N[now].e) {
			if (E[e].vol && N[E[e].des].layer == INF) {
				N[E[e].des].layer = N[now].layer + 1;
				Q.push_back(E[e].des);
			}
		}
	}
	return 0; // cannot go to the terminal
}
int dfs(int src, int minflow=INF) {
	if (src == t)
		return minflow;
	else if (N[src].layer >= N[t].layer)
		return 0;
	for (auto e : N[src].e) {
		if (E[e].vol && N[E[e].des].layer == N[src].layer + 1) {
			int flow = dfs(E[e].des, min(minflow,E[e].vol));
			if (flow) {
				E[e].vol -= flow;
				E[e ^ 1].vol += flow;
				return flow;
			}
		}
	}
	return 0;
}
int dinic() {
	int maxflow = 0;
	while (bfs()) 
		while (int flow = dfs(s))
			maxflow += flow;
	return maxflow;
}
int main() {
	cin >> n >> m >> s >> t;
	int src, des, vol;
	for (int i = 0; i < 2*m; i+=2) {
		cin >> E[i].src >> E[i].des >> E[i].vol;
		E[i + 1] = { E[i].des,E[i].src,0 };
		N[E[i].src].e.push_back(i);
		N[E[i].des].e.push_back(i + 1);
	}
	cout << dinic() << endl;
	return 0;
}
