//最大费用最大流
#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3fffffff, maxn = 3000;
int n, m, k, W, t, cnte=0, cntn=0;
long long maxflow = 0, maxcost = 0;
struct edge {
	int src, des, vol, cost;
}E[maxn+1];
struct node {
	vector<int> eno;
	bool vis;
	int cost, pre;
}N[maxn+1];
void addEdge(int src, int des, int vol, int cost) {
	N[src].eno.push_back(cnte);
	E[cnte++] = { src, des, vol, cost };
	N[des].eno.push_back(cnte);
	E[cnte++] = { des, src, 0, -cost };
}
void addFilm(int s, int e, int cost, int type) {
	addEdge(2 * s, cntn, 1, cost - W*(!type));
	addEdge(2 * s + 1, cntn, 1, cost - W*type);
	addEdge(cntn++, 2 * e + type, 1, 0);
}
void init() {
	cnte = maxflow = maxcost = 0;
	for (int i = 0; i <= maxn; ++i)
		N[i].eno.clear();
	addEdge(0, 1, k, 0);
	addEdge(1, 2, INF, 0);
	addEdge(1, 3, INF, 0);
	for (int i = 2; i < 2 * n; i += 2) {
		addEdge(i, i + 2, INF, 0);
		addEdge(i + 1, i + 3, INF, 0);
	}
	addEdge(2 * n, 2 * n + 2, INF, 0);
	addEdge(2 * n + 1, 2 * n + 2, INF, 0);
	cntn = 2 * n + 3;
}
bool work() {
	if (N[2 * n + 2].cost == -INF)
		return 0;
	int now = 2 * n + 2, minflow = INF;
	do {
		minflow = min(minflow, E[N[now].pre].vol);
		now = E[N[now].pre].src;
	} while (now != 0);
	now = 2 * n + 2;
	do {
		E[N[now].pre].vol -= minflow;
		E[N[now].pre ^ 1].vol += minflow;
		now = E[N[now].pre].src;
	} while (now != 0);
	maxflow += minflow;
	maxcost += minflow * N[2 * n + 2].cost;
	return 1;
}

bool spfa() {
	//src=0 des=2*n+2
	for (int i = 0; i <= maxn; ++i)
		N[i].vis = 0, N[i].cost = -INF;
	N[0].cost = 0;
	deque<int> Q;
	Q.push_back(0);
	while (Q.size()) {
		int now = Q.front(); Q.pop_front(); N[now].vis = 0;
		for (auto eno : N[now].eno) {
			edge &e = E[eno];
			if (e.vol && (N[e.des].cost < N[e.src].cost + e.cost)) {
				N[e.des].cost = N[e.src].cost + e.cost;
				N[e.des].pre = eno;
				if (!N[e.des].vis) {
					if (Q.size() == 0 || N[e.des].cost > N[Q.front()].cost)//slf
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

void maxCostMaxFlow() {
	while (spfa());
}


int main() {
	cin >> t;
	while (t--) {
		cin >> n >> m >> k >> W;
		init();
		int src, des, w, op;
		for (int i = 0; i < m; ++i) {
			cin >> src >> des >> w >> op;
			addFilm(src, des, w, op);
		}
		maxCostMaxFlow();
		cout << maxcost << endl;
	}
	return 0;
}