#include <bits/stdc++.h>
using namespace std;
const int maxn = 100001, maxe=200001;
int dis[maxn];
bool visited[maxn];
struct edge {
	int src, end, len;
};
struct node {
	vector<int> edge;
};
node N[maxn]; 
vector<edge> E;
int n, m, s;
int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m >> s;
	edge tmp;
	for (int i = 0; i < m; ++i) {
		cin >> tmp.src >> tmp.end >> tmp.len;
		E.push_back(tmp);
		N[tmp.src].edge.push_back(i);
	}
	struct op {
		int no, dis;
		bool operator>(const op& x)const {
			return dis > x.dis;
		}
	};
	for (int i = 0; i <= n; ++i)
		dis[i] = 0x7fffffff;
	priority_queue<op,vector<op>,greater<op>> Q;
	Q.push({ s,dis[s]=0 });
	while (Q.size()) {
		const op now = Q.top();Q.pop();
		if (visited[now.no])
			continue;
		visited[now.no] = true;
		for (auto eno : N[now.no].edge) 
			if (!visited[E[eno].end] && now.dis + E[eno].len < dis[E[eno].end]) 
				Q.push({ E[eno].end ,dis[E[eno].end]= now.dis + E[eno].len });
	}
	for (int i = 1; i <= n; ++i)
		cout << dis[i] << ' ';
	return 0;
}