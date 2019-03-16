 #include <iostream>
 #include <vector>
 using namespace std;
 struct Node {
 	int data = -1;
 	Node *l_child = nullptr;
 	Node *r_child = nullptr;
 };
 vector<int>pre;
 vector<int>in;
 int index = 0;
Node *Create(int pre_l, int pre_r, int in_l, int in_r, int index) {
 		if (pre_l > pre_r)
 			return nullptr;
 		Node *node = new Node;
 		node->data = pre[pre_l];
 		int k = 0;
 		for (k = in_l;k <= in_r;++k) {
 			if (in[k] == pre[pre_l])
				break;	
		}
		int num_left = k - in_l;
		node->l_child = Create(pre_l + 1, pre_l + num_left, in_l, k - 1, index + 1);
		node->r_child = Create(pre_l + num_left + 1, pre_r, k + 1, in_r, index + 1);
		return node;
 }
 vector<int>post;
 void PostOrder(Node *root) {
 	if (root == nullptr)
 		return ;
	PostOrder(root->l_child);
	PostOrder(root->r_child);
//	printf("%d ", root->data);
	post.push_back(root->data); 
 }
 int main() {
 	int n = 0;
 	scanf("%d", &n);
 	for (int i = 0;i < n;++i) {
 		int e = 0;
		scanf("%d", &e);
		pre.push_back(e);	
	}
	for (int i = 0;i < n;++i) {
 		int e = 0;
		scanf("%d", &e);
		in.push_back(e);	
	}
	auto root = Create(0, n - 1, 0, n - 1, 0);
	PostOrder(root);
	printf("%d", post[0]);
	return 0;
 }
