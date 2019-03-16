#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
struct Node {
	int data = -1;
	Node *l_child = nullptr;
	Node *r_child = nullptr;
};
vector<int>in;
vector<int>pre;
Node *Create(int pre_l, int pre_r, int in_l, int in_r) {
	if (pre_l > pre_r)
		return nullptr;
	Node *root = new Node;
	root->data = pre[pre_l];
	int k = 0;
	for(k = in_l;k <= in_r;++k)
		if (in[k] == pre[pre_l])
			break;
	int num_left = k - in_l;
	root->l_child = Create(pre_l + 1, pre_l + 1 + num_left - 1, in_l, k - 1);
	root->r_child = Create(pre_l + 1 + num_left, pre_r, k + 1, in_r);
	return root;
}
void InOrder(Node *root) {
	if (root == nullptr)
		return ;
	InOrder(root->l_child);
	printf("%d ", root->data);
	InOrder(root->r_child);
}
int a = 0;
int b = 0;
Node *Search(Node *root) {
	if (!root || root->data == a || root->data == b)
		return root;
	Node *left = Search(root->l_child);
	Node *right = Search(root->r_child);
	if (left && right)
		return root;
	return left != nullptr ? left : right;
} 
int main() {
	int m = 0;
	int n = 0;
	scanf("%d %d", &m, &n);
	unordered_map<int, bool> mp; 
	for (int i = 0;i < n;++i) {
		int e = 0;
		scanf("%d", &e);
		in.push_back(e);
		mp[e] = true;
	}
	for (int i = 0;i < n;++i) {
		int e = 0;
		scanf("%d", &e);
		pre.push_back(e);
	}	
	Node *root = Create(0, n - 1, 0, n - 1);
//	InOrder(root);
	for (int i = 0;i < m;++i) {
		scanf("%d %d", &a, &b);
		if (mp[a] && mp[b]) {
			Node *res = Search(root);
			if (res->data == a) 
				printf("%d is an ancestor of %d.", a, b);
			else if (res->data == b)
				printf("%d is an ancestor of %d.", b, a);	
			else
				printf("LCA of %d and %d is %d.", a, b, res->data);
		}
		else if (!mp[a] && mp[b]) {
			printf("ERROR: %d is not found.", a);
		}
		else if (mp[a] && !mp[b]) {
			printf("ERROR: %d is not found.", b);	
		}
		else {
			printf("ERROR: %d and %d are not found.", a, b);
		}
		printf("\n");
	}

	return 0;
}
