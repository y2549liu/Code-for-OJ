#include <bits/stdc++.h>
using namespace std;
const int maxn = 3000;
const double eps = 1e-9;
struct rectangle {
	double x1, y1, x2, y2;
}rect[maxn];
struct horizontalLine {
	double x1, x2, y;
	int no, type;
	bool operator<(const horizontalLine x) const {
		return (y < x.y);
	}
}hl[maxn];
vector<double> vl;
//×ó±ÕÓÒ¿ª
struct node {
	int l, r, mid, cover;
	double dist;
	node *pl, *pr;
	void pushdown() {
		if (cover) {
			pl->addEdge(l, mid, cover);
			pr->addEdge(mid, r, cover);
			cover = 0;
		}
	}
	void pushup() {
		if (cover>=2)
			dist = vl[r] - vl[l];
		else if (l + 1 == r)
			dist = 0;
		else {
			pushdown();
			dist = pl->dist + pr->dist;
		}
	}
	void addEdge(int el, int er ,int adds=1) {
		if (el <= l && er >= r) {
			cover+=adds;
			pushup();
			return;
		}
		if (el < mid)
			pl->addEdge(el, er, adds);
		if (er > mid)
			pr->addEdge(el, er, adds);
		pushup();
	}
	void delEdge(int el, int er) {
		if (el <= l && er >= r && cover) {
			--cover;
			pushup();
			return;
		}
		pushdown();
		if (el < mid) 
			pl->delEdge(el, er);
		if (er > mid) 
			pr->delEdge(el, er);
		pushup();
	}
	node(int _l, int _r) :l(_l), r(_r), mid((l + r) >> 1), pr(nullptr), pl(nullptr), cover(0), dist(0) {
		if (l + 1 < r) {
			pl = new node(l, mid);
			pr = new node(mid, r);
		}
	}
	~node() {
		if (l < r - 1) {
			delete pl;
			delete pr;
		}
	}
};

int main() {
	ios::sync_with_stdio(0);
	int t, n, cnt = 0;	cin >> t;
	double x1, x2, y1, y2;
	while (t--) {
		cin >> n;
		vl.clear(); vl.resize(maxn);
		memset(rect, 0, sizeof(rect));
		memset(hl, 0, sizeof(hl));
		for (int i = 0; i < n; ++i) {
			cin >> x1 >> y1 >> x2 >> y2;
			rect[i] = { x1,y1,x2,y2 };
			hl[i << 1] = { x1,x2,y2 ,i,-1 };
			hl[(i << 1) + 1] = { x1,x2,y1 ,i,1 };
			vl[i << 1] = x1;
			vl[(i << 1) + 1] = x2;
		}
		sort(vl.begin(), vl.begin() + 2 * n);
		vl.erase(unique(vl.begin(), vl.begin() + 2 * n), vl.end());
		sort(hl, hl + 2 * n);
		node tree(0, vl.size() - 1);
		double ans = 0;
		for (int i = 0; i < 2 * n; ++i) {
			if (i)
				ans += tree.dist*(hl[i].y - hl[i - 1].y);
			int nol = lower_bound(vl.begin(), vl.end(), hl[i].x1) - vl.begin(), nor = lower_bound(vl.begin(), vl.end(), hl[i].x2) - vl.begin();
			if (hl[i].type == 1)
				tree.addEdge(nol, nor);
			else
				tree.delEdge(nol, nor);
		}
		cout << fixed << setprecision(2) << ans+eps << endl;
	}
	return 0;
}