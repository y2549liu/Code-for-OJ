#include <bits/stdc++.h>
using namespace std;
const int maxn = 400000;
typedef long long LL;
int cnt=0, n, m;
LL num[100001];
struct node {
	int l, r, mid, lno, rno;
	LL val, add;
	void biuld(const int &_l, const int &_r);
	void addnode(const LL &_add);
	void addseg(const int &_l, const int &_r, const LL &_add);
	LL questseg(const int &_l, const int &_r);
	void pushdown();
	void pushup();
}tree[maxn];

void node::biuld(const int & _l, const int & _r) {
	l = _l; r = _r; mid = (l + r) >> 1;
	if (l == r)
		val = num[l];
	else {
		tree[lno = ++cnt].biuld(l, mid);
		tree[rno = ++cnt].biuld(mid+1, r);
		pushup();
	}
}

void node::addnode(const LL & _add)
{
	add += _add;
	val += LL(r - l + 1) * _add;
}

void node::addseg(const int & _l, const int & _r, const LL & _add)
{
	if (l == _l && r==_r) {
		addnode(_add);
		return;
	}
	pushdown();
	if (mid >= _r) 
		tree[lno].addseg(_l, _r, _add);
	else if (mid < _l)
		tree[rno].addseg(_l, _r, _add);
	else
		tree[lno].addseg(_l, mid, _add), tree[rno].addseg(mid+1, _r, _add);
	pushup();
}

LL node::questseg(const int & _l, const int & _r)
{
	if (l == _l && r == _r) 
		return val;
	pushdown();
	if (mid >= _r)
		return tree[lno].questseg(_l, _r);
	else if (mid < _l)
		return tree[rno].questseg(_l, _r);
	else
		return tree[lno].questseg(_l, mid)+ tree[rno].questseg(mid + 1, _r);
}

void node::pushdown()
{
	if (add && l != r) {
		tree[lno].addnode(add);
		tree[rno].addnode(add);
		add = 0;
	}
}

void node::pushup()
{
	if (l != r)
		val = tree[lno].val + tree[rno].val;
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		cin >> num[i];
	tree[0].biuld(1,n);
	int type, l, r;
	long long add;
	while (m--) {
		cin >> type >> l >> r;
		if (type == 1) {
			cin >> add;
			tree[0].addseg(l, r, add);
		}
		else
			cout << tree[0].questseg(l, r) <<endl;
	}
	return 0;
}