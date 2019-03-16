#include <iostream>
#include <vector>
#include <stack>
using namespace std;
struct Node {
	int data = -1;
	Node *l_child = nullptr;
	Node *r_child = nullptr; 
};

vector<int>pre;
vector<int>inorder;

Node *Create(int pre_l, int pre_r, int in_l, int in_r) {
	if (pre_l > pre_r) {
		return nullptr;
	}
	Node *root = new Node;
	root->data = pre[pre_l];
	int k = 0;
	for (k = in_l;k <= in_r;++k) {
		if (inorder[k] == pre[pre_l])
			break;
	}
	int num_left = k - in_l;
	root->l_child = Create(pre_l + 1, pre_l + num_left, in_l, k - 1);
	root->r_child = Create(pre_l + num_left + 1, pre_r, k + 1, in_r);
	return root;
}
int flag = 0;
void PostOrder(Node *root) {
	if (root == nullptr)
		return ;
	if (root->l_child)
		PostOrder(root->l_child);
	if (root->r_child)
		PostOrder(root->r_child);
	if (flag)
		printf(" ");
	flag = 1;
	printf("%d", root->data);
}
int main() {
	int n = 0;
	scanf("%d", &n);
	getchar();
	stack<int>s;
	for (int i = 0;i < 2 * n;++i) {
		string str;
		getline(cin, str);
		if (str[1] == 'u') {
			int e = -1;
			if (str.length() == 6)
				e = str[5] - '0';
			else {
				int pos = str.find(" ");
				auto sub = str.substr(pos + 1, str.length() - pos);
				e = stoi(sub);
			}
			s.push(e);
			pre.push_back(e);
		}
		else {
			int e = s.top();
			s.pop();
			inorder.push_back(e);
		}
	}
	Node *root = Create(0, n - 1, 0, n - 1);
	PostOrder(root);
	return 0;
}
