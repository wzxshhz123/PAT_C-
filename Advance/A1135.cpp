#include <iostream>
using namespace std;
struct Node {
	int data = -1;
	Node *l_child = nullptr;
	Node *r_child = nullptr;
	int type = -1;
}; 
void Insert(Node *&root, int v) {
	if (root == nullptr) {
		root = new Node;
		root->data = abs(v);
		root->type = v > 0 ? 1 : 0;
		return ;
	}
	else if (root->data > abs(v)) {
		Insert(root->l_child, v);
	}
	else if (root->data < abs(v)) {
		Insert(root->r_child, v);
	}
}
int ChildrenCheck(Node *root) {
	if (!root)
		return true;
	if (root) {
		if (root->l_child) {
			if (root->type == 0 && root->l_child->type == 0)
				return false;
		}
		if (root->r_child) {
			if (root->type == 0 && root->r_child->type == 0)
				return false;
		}
	}
	return ChildrenCheck(root->l_child) && ChildrenCheck(root->r_child);
}
int GetHeight(Node *root) {
	if (!root)
		return 0;
	int l = GetHeight(root->l_child);
	int r = GetHeight(root->r_child);
	if (root->type > 0)
		return max(l, r) + 1;
	else
		return max(l, r);
}
int HeightCheck(Node *root) {
	if (!root)
		return true;
	int l = GetHeight(root->l_child);
	int r = GetHeight(root->r_child);
	if (l != r)
		return false;
	return HeightCheck(root->l_child) && HeightCheck(root->r_child);
}
int main() {
	int k = 0;
	scanf("%d", &k);
	while (k--) {
		int n = 0;
		scanf("%d", &n);
		Node *root = nullptr;
		for (int i = 0;i < n;++i) {
			int e = 0;
			scanf("%d", &e);
			Insert(root, e);
		}
		if (root->type > 0 && ChildrenCheck(root) && HeightCheck(root))
			printf("Yes\n");
		else
			printf("No\n");
		
	}
}
