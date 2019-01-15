#include <bits/stdc++.h>
using namespace std;

const int maxn = 5001, maxm = 200001;
int parent[maxn];
struct edge {
	int src, des, len;
	bool operator==(const edge& e) const {
		return (src==e.src && des==e.des &&len==e.len);
	}
	bool operator<(const edge& e) const {
		if (len != e.len)
			return (len < e.len);
		else if (src != e.src)
			return (src < e.src);
		else
			return (des < e.des);
	}
};
int find_parent(int x){
	if (parent[x] == x)
		return x;
	else
		return parent[x]=find_parent(parent[x]);
}
int main() {
	ios::sync_with_stdio(false);
	int n, m, src, des, len;
	long long ans = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		parent[i] = i;
	set<edge> edges;
	for (int i = 0; i < m; ++i) {
		cin >> src >> des >> len;
		if (src > des)
			swap(src, des);
		edges.insert({ src,des,len });
	}
	int cnt = 0;
	for (auto e : edges) {
		int pasrc = find_parent(e.src), pades = find_parent(e.des);
		if (pasrc==pades)
			continue;
		else {
			++cnt;
			ans += e.len;
			parent[pasrc] = pades;
		}
	}
	if (cnt == n-1)
		cout << ans;
	else
		cout << "orz";
	return 0;
}
