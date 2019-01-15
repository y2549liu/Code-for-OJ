#include<bits/stdc++.h>
#define MAXN 1000001
using namespace std;
int b[MAXN],cnt = 0, n, q, l, r;
struct node {
	int l, r, mid, leftno, rightno, adds, segmin, val;
	void biuld(const int &_l, const int &_r);
	void add(const int &v = 1);
	void pushdown();
	void pushup();
	void transverse();
	void addseg(const int &_l, const int &_r);
	int questseg(const int &_l, const int &_r);
}tree[MAXN];
void init() {
	cnt = 0;
	memset(tree, 0, sizeof(tree));
}
int main()
{
	char act[10];
	while (cin >> n >> q) {
		init();
		for (int i = 1; i <= n; i++)
			scanf("%d", b + i);
		tree[0].biuld(1, n);
		while (q--)
		{
			scanf("%s %d %d", act, &l, &r);
			if (act[0] == 'a') {
				tree[0].addseg(l, r);
				//tree[0].transverse();
				//printf("\n");
			}
			else
				printf("%d\n", tree[0].questseg(l, r));
		}
	}
	return 0;
}

inline void node::biuld(const int & _l, const int & _r) {
	l = _l; r = _r;
	mid = (l + r) >> 1;
	if (l == r) {
		segmin = b[l];
		return;
	}
	tree[leftno = ++cnt].biuld(l, mid);
	tree[rightno = ++cnt].biuld(mid + 1, r);
	segmin = min(tree[leftno].segmin, tree[rightno].segmin);
}

inline void node::add(const int &v) {
	adds += v;
	segmin -= v;
	if (segmin == 0) {
		if (l == r)
		{
			++val;
			adds = 0;
			segmin = b[l];
		}
		else {
			pushdown();
			pushup();
		}
	}
}

inline void node::pushdown() {
	tree[leftno].add(adds);
	tree[rightno].add(adds);
	adds = 0;
}

inline void node::pushup() {
	val = tree[leftno].val + tree[rightno].val;
	segmin = min(tree[leftno].segmin, tree[rightno].segmin);
}
//only for debug 
void node::transverse()
{
	if (l == r) {
		printf("%d ", (val + 1)*b[l] - segmin);
		return;
	}
	pushdown();
	tree[leftno].transverse();
	tree[rightno].transverse();
}
//the major principle of segment tree is to be lazy 
inline void node::addseg(const int & _l, const int & _r) {
	if (_l == l && _r == r) {
		add();
		return;
	}
	pushdown();
	if (_r <= mid)
		tree[leftno].addseg(_l, _r);
	else if (_l > mid)
		tree[rightno].addseg(_l, _r);
	else
		tree[leftno].addseg(_l, mid), tree[rightno].addseg(mid + 1, _r);
	pushup();
}

inline int node::questseg(const int & _l, const int & _r) {
	if (_l == l && _r == r)
		return val;
	if (adds) pushdown();
	if (_r <= mid)
		return tree[leftno].questseg(_l, _r);
	else if (_l > mid)
		return tree[rightno].questseg(_l, _r);
	else
		return tree[leftno].questseg(_l, mid) + tree[rightno].questseg(mid + 1, _r);
}
