#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll , ll> pii;

pii Minus(pii a, pii b) {
	return make_pair(a.first - b.first, a.second - b.second);
}
ll squaredis(pii a, pii b) {
	return (a.first - b.first)*(a.first - b.first) + (a.second - b.second)*(a.second - b.second);
}
ll Mul(pii a, pii b) {
	return (a.first * b.first + a.second * b.second);
}

bool isoblong(pii p[4]) {
	if ( (p[0]==p[1]) || (p[2]== p[1]) || (p[3] == p[2]))
		return 0;
	if ((Minus(p[1], p[0])!= Minus(p[3], p[2])))
		return 0;
	if (squaredis(p[1], p[0]) == squaredis(p[1], p[3]))
		return 0;
	if (Mul(Minus(p[1], p[0]), Minus(p[1], p[3]))!=0)
		return 0;
	return 1;
}
bool isRightTri(pii p[3]) {
	if ((p[0]== p[1]) || (p[2]== p[1]))
		return 0;
	if ((p[2].second - p[1].second)*(p[1].first - p[0].first) ==
		(p[1].second - p[0].second)*(p[2].first - p[1].first))
		return 0;
	ll dis[3];
	dis[0] = squaredis(p[0], p[1]);
	dis[1] = squaredis(p[2], p[1]);
	dis[2] = squaredis(p[0], p[2]);
	sort(dis, dis + 3);
	return (dis[0] + dis[1] - dis[2])==0;
}
int main() {
	int n,ans=0;
	cin >> n;
	pii points[20];
	ll x[20], y[20];
	for (int i = 0; i < n; ++i) {
		cin >> x[i];
	}
	for (int i = 0; i < n; ++i) {
		cin >> y[i];
		points[i] = make_pair(x[i], y[i]);
	}	
	sort(points, points+n);
	bool vis[20] = { 0 };
	for (int i = 0; i < n-3; ++i) {
		vis[i] = 1;
		for (int j = i + 1; j < n-2; ++j) {
			vis[j] = 1;
			for (int k = j + 1; k < n - 1; ++k) {
				vis[k] = 1;
				for (int u = k + 1; u < n; ++u) {
					vis[u] = 1;
					pii p[4] = { points[i],points[j],points[k],points[u] };
					
					if (isoblong(p)) {
						for (int v = 0; v < n - 2; ++v) {
							if (vis[v])
								continue;
							vis[v] = 1;
							for (int w = v+1; w < n - 1; ++w) {
								if (vis[w])
									continue;
								vis[w] = 1;
								for (int e = w+1; e < n; ++e) {
									if (vis[e])
										continue;
									pii q[3] = { points[v],points[w],points[e] };
									if (isRightTri(q)) {
								
										++ans;
									}
								}
								vis[w] = 0;
							}
							vis[v] = 0;
						}
					}
					vis[u] = 0;
				}
				vis[k] = 0;
			}
			vis[j] = 0;
		}
		vis[i] = 0;
	}
	cout << ans <<endl;
	return 0;
}