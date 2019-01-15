#include <bits/stdc++.h>
using namespace std;
const int maxn = 400000;
typedef long long LL;
int cnt = 0, n, m, p;
LL num[100001];

LL fastpow(const LL &base, const LL &exp) {
	if (exp == 1)
		return base;
	LL ans = fastpow(base, exp >> 1);
	ans *= ans;
	ans %= p;
	if (exp & 1)
		return (ans*base) % p;
	else
		return ans;
}

struct node {
	int l, r, mid, lno, rno;
	LL val, add, mul;
	void biuld(const int &_l, const int &_r);
	void addnode(const LL &_add);
	void mulnode(const LL &_mul);
	void addseg(const int &_l, const int &_r, const LL &_add);
	void mulseg(const int &_l, const int &_r, const LL &_mul);
	LL questseg(const int &_l, const int &_r);
	void pushdown();
	void pushup();
}tree[maxn];

void node::biuld(const int & _l, const int & _r) {
	l = _l; r = _r; mid = (l + r) >> 1; mul = 1; add = 0;
	if (l == r)
		val = num[l]%p;
	else {
		tree[lno = ++cnt].biuld(l, mid);
		tree[rno = ++cnt].biuld(mid + 1, r);
		pushup();
	}
}

void node::addnode(const LL & _add)
{
	if (!_add)
		return;
	add += _add;
	val += LL(r - l + 1) * _add;
}

void node::mulnode(const LL & _mul)
{
	if (_mul == 1)
		return;
	mul *= _mul;
	val = (val*_mul) % p;
	add = (add*_mul) % p;
}

void node::addseg(const int & _l, const int & _r, const LL & _add)
{
	if (l == _l && r == _r) {
		addnode(_add);
		return;
	}
	pushdown();
	if (mid >= _r)
		tree[lno].addseg(_l, _r, _add);
	else if (mid < _l)
		tree[rno].addseg(_l, _r, _add);
	else
		tree[lno].addseg(_l, mid, _add), tree[rno].addseg(mid + 1, _r, _add);
	pushup();
}

void node::mulseg(const int & _l, const int & _r, const LL & _mul)
{
	if (l == _l && r == _r) {
		mulnode(_mul);
		return;
	}
	pushdown();
	if (mid >= _r)
		tree[lno].mulseg(_l, _r, _mul);
	else if (mid < _l)
		tree[rno].mulseg(_l, _r, _mul);
	else
		tree[lno].mulseg(_l, mid, _mul), tree[rno].mulseg(mid + 1, _r, _mul);
	pushup();
}

LL node::questseg(const int & _l, const int & _r)
{
	if (l == _l && r == _r)
		return val%p;
	pushdown();
	if (mid >= _r)
		return tree[lno].questseg(_l, _r) % p;
	else if (mid < _l)
		return tree[rno].questseg(_l, _r) % p;
	else
		return (tree[lno].questseg(_l, mid) + tree[rno].questseg(mid + 1, _r))%p;
}

void node::pushdown()
{
	if (l != r) {
		tree[lno].mulnode(mul);
		tree[rno].mulnode(mul);
		tree[lno].addnode(add);
		tree[rno].addnode(add);
		add = 0;
		mul = 1;
	}
}

void node::pushup()
{
	if (l != r)
		val = tree[lno].val + tree[rno].val;
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m >> p;
	for (int i = 1; i <= n; ++i)
		cin >> num[i];
	tree[0].biuld(1, n);
	int type, l, r;
	long long add,mul;
	while (m--) {
		cin >> type >> l >> r;
		if (type == 1) {
			cin >> mul;
			tree[0].mulseg(l, r, mul);
		}
		else if (type == 2) {
			cin >> add;
			tree[0].addseg(l, r, add);
		}
		else
			cout << (p+tree[0].questseg(l, r))%p << endl;
	}
	return 0;
}