#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3fffffff;
int n, m, s, t;
long long maxflow = 0, mincost = 0;
struct edge {
	int src, des, vol, cost;
}E[110001];
struct node {
	vector<int> eno;
	bool vis;
	int cost, pre;
}N[5100];
bool work() {
	if (N[t].cost == INF)
		return 0;
	int now = t, minflow = INF;
	do {
		minflow = min(minflow, E[N[now].pre].vol);
		now = E[N[now].pre].src;
	} while (now != s);
	now = t;
	do {
		E[N[now].pre].vol -= minflow;
		E[N[now].pre ^ 1].vol += minflow;
		now = E[N[now].pre].src;
	} while (now != s);
	maxflow += minflow;
	mincost += minflow * N[t].cost;
	return 1;
}
void init() {
	for (int i = 1; i <= n; ++i)
		N[i].vis = 0, N[i].cost = INF;
	N[s].cost = 0;
}
bool spfa() {
	init();
	deque<int> Q;
	Q.push_back(s); 
	while (Q.size()) {
		int now = Q.front(); Q.pop_front(); N[now].vis = 0;
		for (auto eno : N[now].eno) {
			edge &e = E[eno];
			if (e.vol && (N[e.des].cost > N[e.src].cost + e.cost)) {
				N[e.des].cost = N[e.src].cost + e.cost;
				N[e.des].pre = eno;
				if (!N[e.des].vis) {
					if (N[e.des].cost < N[Q.front()].cost)//slf
						Q.push_front(e.des);
					else
						Q.push_back(e.des);
					N[e.des].vis = 1;
				}
			}
		}
	}
	return work();
}
bool dijkstra() {
	struct nodeCost {
		int no, dis;
		bool operator<(const nodeCost & x) const {
			return (dis > x.dis);
		}
	};
	init();
	priority_queue<nodeCost> Q;
	Q.push({ s,0 });
	while (Q.size()) {
		int src = Q.top().no;
		Q.pop();
		if (N[src].vis)
			continue;
		N[src].vis = 1;
		for (auto eno : N[src].eno) {
			edge &e = E[eno];
			if (e.vol && (N[e.des].cost > N[e.src].cost + e.cost)) {
				N[e.des].cost = N[e.src].cost + e.cost;
				N[e.des].pre = eno;
				Q.push({ e.des, N[e.des].cost });
			}
		}
	}
	return work();
}
void minCostMaxFlow(){
	while (spfa());
}


int main() {
	cin >> n >> m >> s >> t;
	int src, des, vol, cost;
	for (int i = 0; i < 2*m; i+=2) {
		cin >> src >> des >> vol >> cost;
		E[i] = { src,des,vol,cost };
		E[i + 1] = { des,src,0,-cost };
		N[src].eno.push_back(i);
		N[des].eno.push_back(i + 1);
	}
	minCostMaxFlow();
	cout << maxflow << " " << mincost;
	return 0;
}