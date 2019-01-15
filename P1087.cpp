#include <bits/stdc++.h>
using namespace std;
char tmp;
struct node {
	node *parant, *left, *right;
	char data;
};
void biuld(int depth, node* root) {
	if (depth) {
		root->left = new node;
		root->left->parant = root;
		biuld(depth - 1, root->left);
		root->right = new node;
		root->right->parant = root;
		biuld(depth - 1, root->right);
		if (root->right->data == root->left->data)
			root->data = root->left->data;
		else
			root->data = 'F';
	}
	else {
		root->left = root->right = nullptr;
		cin >> tmp;
		if (tmp=='1')
			root->data = 'I';
		else
			root->data = 'B';
	}
}
void clear(node *root) {
	if (root->left)
		clear(root->left);
	if (root->right)
		clear(root->right);
	delete root;
}
void transverse(node *root) {
	if (root == nullptr)
		return;
	transverse(root->left);
	transverse(root->right);
	cout << root->data;
}
struct tree {
	node *root;
	tree() {
		root = new node;
	}
	~tree() {
		clear(root);
	}
};
int main() {
	int n;
	cin >> n;
	tree T;
	biuld(n, T.root);
	transverse(T.root);
	return 0;
}