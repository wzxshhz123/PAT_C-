#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct Node {
	int data = -1;
	Node *l_child;
	Node *r_child;
};
vector<int>inorder;
vector<int>post;

Node *Create(int post_l, int post_r, int in_l, int in_r) {
	if (post_l > post_r) {
		return nullptr;
	}
	Node *node = new Node;
	node->data = post[post_r];
	int k = 0;
	for (k = in_l;k <= in_r;++k) {
		if (inorder[k] == post[post_r])
			break;
	}
	int num_left = k - in_l;
	node->l_child = Create(post_l, post_l + num_left - 1, in_l, k - 1);
	node->r_child = Create(post_l + num_left, post_r - 1, k + 1, in_r);
	return node;
} 
int flag = 0;
void BFS(Node *root) {
	queue<Node*>q;
	q.push(root);
	while (!q.empty()) {
		auto node = q.front();
		q.pop();
		if (flag)
			printf(" ");
		flag = 1;
		printf("%d", node->data);
		if (node->l_child) {
			q.push(node->l_child);
		}
		if (node->r_child) {
			q.push(node->r_child);
		}
	}
}
int main() {
	int n = 0;
	scanf("%d", &n);
	for (int i = 0;i < n;++i) {
		int e = 0;
		scanf("%d", &e);
		post.push_back(e);
	}
	for (int i = 0;i < n;++i) {
		int e = 0;
		scanf("%d", &e);
		inorder.push_back(e);
	}
	Node *root = Create(0, n - 1, 0, n - 1);
	BFS(root);
	return 0;
}
