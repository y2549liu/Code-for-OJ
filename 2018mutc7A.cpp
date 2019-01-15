#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
int n, m;
struct edge {
	int src, des, wt;
}E[200001];
struct node {
	vector<int> eno;
	int pre,cost;
}N[100001];
int main() {
	ios::sync_with_stdio(false);
	while(cin>>n>>m){
		for (int i = 0; i <= n; ++i) {
			N[i].eno.clear();
			N[i].pre = 0;
			N[i].cost = 0x3fffffff;
		}
		for (int i = 1; i <= m; ++i) {
			cin >> E[i].src >> E[i].des >> E[i].wt;
			N[E[i].src].eno.push_back(i);
			N[E[i].des].eno.push_back(i);
		}
		N[1].cost = 0;
		struct nodeCost {
			int no, cost;
			bool operator<(const nodeCost& x)const {
				return cost > x.cost;
			}
		};
		priority_queue<nodeCost> Q; Q.push({ 1,0 });
		while (Q.size()) {
			int src = Q.top().no, cost = Q.top().cost; Q.pop();
			if (N[src].cost != cost)
				continue;
			for (auto eno : N[src].eno) {
				int des = src^ E[eno].src^ E[eno].des;
				if (N[des].cost > N[src].cost + (N[src].pre != E[eno].wt)) {
					N[des].cost = N[src].cost + (N[src].pre != E[eno].wt);
					N[des].pre = E[eno].wt;
					Q.push({ des,N[des].cost });
				}
			}
		}
		if (N[n].cost == 0x3fffffff)
			cout << "-1";
		else
			cout << N[n].cost;
		cout << endl;
	}
	return 0;
}