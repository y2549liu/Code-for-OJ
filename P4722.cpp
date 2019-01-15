//网络流 HLPP n^2*sqrt(m)
#include <bits/stdc++.h>
using namespace std;
const int INF = 0x7fffffff;
int n, m, s, t, cnt[10002];
struct edge {
	int src, des, vol;
}E[240002];
struct node {
	vector<int> eno;
	int flow, h;
}N[10002];

int push(int src, int des, int eno) {
	int maxflow = min(N[src].flow, E[eno].vol);
	E[eno].vol -= maxflow;
	E[eno ^ 1].vol += maxflow;
	N[src].flow -= maxflow;
	N[des].flow += maxflow;
	return maxflow;
}
void gap(int h) {
	for (int i = 1; i <= n; ++i)
		if (i != s && i != t && N[i].h > h)
			N[i].h = n + 1;
}
int hlpp(){
	N[s].h = n; N[s].flow = INF;
	struct nodeh{
		int no, h;
		bool operator<(const nodeh& x) const {
			return h < x.h;
		}
	};
	priority_queue<nodeh> Q;
	Q.push({ s,n });
	while (Q.size()) {
		int now = Q.top().no; Q.pop();
		if (N[now].flow == 0)
			continue;
		for (auto eno : N[now].eno) {
			if (N[now].flow == 0)
				break;
			int &des = E[eno].des;
			if ((now == s || N[now].h == N[des].h + 1) \
				&& push(now, des, eno) \
				&& des != s  && des != t)  //起点和终点不需要推流
				Q.push({ des,N[des].h });
		}
		if (now != s && now != t && N[now].flow) { //flow stuck
			if (!(--cnt[N[now].h])) 
				gap(N[now].h);
			++cnt[++N[now].h];
			Q.push({ now,N[now].h });
		}
	}
	return N[t].flow;
}

int main() {
	cin >> n >> m >> s >> t;
	int src, des, vol;
	for (int i = 0; i < 2*m; i+=2) {
		cin >> src >> des >> vol;
		E[i] = { src,des,vol };
		E[i + 1] = { des,src,0 };
		N[src].eno.push_back(i);
		N[des].eno.push_back(i + 1);
	}
	cout << hlpp();
	return 0;
}