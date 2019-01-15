#include <bits/stdc++.h>
using namespace std;
struct node {
	using pnode = node*;
	pnode left, right, parent;
	char data;
	node(pnode _parent, char _data=0) {
		parent = _parent;
		left = right = nullptr;
		data = _data;
	}
};
node* find(node *root, char &data) {
	if (root->data == data)
		return root;
	node* loc = nullptr;
	if (root->left) {
		loc = find(root->left, data);
		if (loc)
			return loc;
	}
	if (root->right) {
		loc = find(root->right, data);
	}
	return loc;
}

void clear(node *root) {
	if (root->left)
		clear(root->left);
	if (root->right)
		clear(root->right);
	delete root;
}
void transverse(node *root) {
	cout << root->data;
	if (root->left)
		transverse(root->left);
	if (root->right)
		transverse(root->right);
}
int main() {
	node* tree = new node(nullptr);
	int n;
	cin >> n;
	char a, b, c;
	cin >> a >> b >> c;
	tree->data = a;
	if (b != '*')
		tree->left = new node(tree, b);
	if (c != '*')
		tree->right = new node(tree, c);

	for (int i = 1; i < n; ++i) {
		cin >> a >> b >> c;
		node *loc = find(tree, a);
		if (b != '*') 
			loc->left = new node(loc, b);
		if (c != '*')
			loc->right = new node(loc, c);
	}
	transverse(tree);
	clear(tree);
	return 0;
}