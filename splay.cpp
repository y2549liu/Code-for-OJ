#include<bits/stdc++.h>
using namespace std;
const int inf = 0x7fffffff;
struct Node *nil;
struct Node {
	int val, size, count;
	Node *ch[2], *fa;
	Node(int v, Node* f) :val(v), size(1), count(1), fa(f) {
		ch[0] = ch[1] = nil;
	}
	int dir() {
		if (fa == nil)
			return -1;
		return (fa->ch[1] == this);
	}
	int cmp(int v) {
		if (val == v)
			return -1;
		return (v > val);
	}
	void update() {
		size = count + ch[0]->size + ch[1]->size;
	}
	void setChild(Node *c, int id) {
		ch[id] = c;
		if (c != nil)
			c->fa = this;
	}
}*root;
void init() {
	nil = new Node(-inf, nullptr);
	root = nil->ch[0] = nil->ch[1] = nil->fa = nil;
	nil->size = nil->count = 0;
}
void rotate(Node *x){
	Node *f = x->fa, *ff=f->fa;
	int id = x->dir(), fid=f->dir(); //id==0 <=> x is the left subtree of it's parent 
	if (id == -1)
		return;
	f->setChild(x->ch[!id], id);
	x->setChild(f, !id);
	x->fa = ff;
	if (ff != nil)
		ff->ch[fid] = x;
	else
		root = x;
	f->update();
}
void splay(Node *f, Node *x) {//continuously rotate x upward until it's father is f
	while (x->fa != f) {
		Node *y = x->fa, *z = y->fa;
		if (z == f) rotate(x);
		else if (x->dir() == y->dir()) rotate(y), rotate(x);
		else rotate(x), rotate(x);
	}
	x->update();
}
Node *find(Node *x, int val) {
	int d = x->cmp(val);
	if (d == -1 || x->ch[d] == nil)
		return x;
	else
		return find(x->ch[d], val);
}
int kth(Node *x, int k) {
	int ss = x->ch[0]->size;
	if (k <= ss) return kth(x->ch[0], k);
	else if (k <= ss + x->count) return x->val;
	else return kth(x->ch[1], k - ss - x->count);
}
int main() {

}