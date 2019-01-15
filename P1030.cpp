#include <bits/stdc++.h>
using namespace std;
struct node {
	using pnode = node*;
	pnode left, right, parent;
	char data;
	node(pnode _parent){
		parent=_parent;
		left=right=nullptr;
	}
};

void biuld(char* inOrder, char* postOrder, int n, node* root) {
	root->data = postOrder[n-1];
	char *pos = strchr(inOrder, root->data);
	if (pos > inOrder) {
		//left son tree is not empty
		root->left = new node(root);
		biuld(inOrder, postOrder, pos - inOrder, root->left);
	}
	if (pos < inOrder + n - 1) {
		root->right = new node(root);
		biuld(pos+1, postOrder+(pos-inOrder), inOrder+n-pos-1 , root->right);
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
	cout << root->data;
	if (root->left)
		transverse(root->left);
	if (root->right)
		transverse(root->right);
}
int main() {
	node* tree=new node(nullptr);
	char inOrder[20], postOrder[20];
	cin >> inOrder >> postOrder;
	biuld(inOrder, postOrder, strlen(inOrder), tree);
	transverse(tree);
	clear(tree);
	return 0;
}