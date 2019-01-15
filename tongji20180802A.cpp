#include <bits/stdc++.h>
using namespace std;
struct node
{
	vector<int> e;
	int dis;
	bool visited;
};
struct edge {
	int src, des, len;
};
struct nodedis {
	int no, dis;
	bool operator<(const nodedis& x) const {
		return dis > x.dis;
	}
};
int main()
{
	int n, m;
	while (cin >> n >> m && n) {
		vector<node> N(n + 1);
		vector<edge> E(m + 1);
		priority_queue<nodedis> Q;
		for (int i = 1; i <= m; ++i) {
			cin >> E[i].src >> E[i].des >> E[i].len;
			N[E[i].src].e.push_back(i);
			N[E[i].des].e.push_back(i);
		}
		for (int i = 2; i <= n; ++i)
			N[i].dis = 0x7ffffff, N[i].visited = 0;
		Q.push({ 1,0 });
		N[1].dis = 0;
		while (Q.size()) {
			nodedis now = Q.top(); Q.pop();
			if (N[now.no].visited)
				continue;
			else 
				N[now.no].visited = 1;
			for (auto i : N[now.no].e) {
				int des = E[i].des^E[i].src^now.no;
				if (!N[des].visited && N[des].dis > N[now.no].dis + E[i].len) {
					N[des].dis = N[now.no].dis + E[i].len;
					Q.push({ des,N[des].dis });
				}
			}
		}
		cout << N[n].dis << endl;
	}

	return 0;
}