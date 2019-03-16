#include <iostream>
#include <vector>
using namespace std;
struct Node {
	int data = -1;
	Node *left = nullptr;
	Node *right = nullptr;
}; 
vector<int>origin;
vector<int>normal_pre;
vector<int>mirror_pre;
vector<int>normal_post;
vector<int>mirror_post;
void InsertNormal(Node *&root, int x) {
	if (root == nullptr) {
		root = new Node;
		root->data = x;
		return ;
	}
	else if (x >= root->data) {
		InsertNormal(root->right, x);
	}
	else 
		InsertNormal(root->left, x);
}
void InsertMirror(Node *&mirror, int x) {
	if (mirror == nullptr) {
		mirror = new Node;
		mirror->data = x;
		return ;
	}
	else if (x >= mirror->data) {
		InsertMirror(mirror->left, x);
	}
	else 
		InsertMirror(mirror->right, x);
}
void PreOrder(Node *root, vector<int> &vi) {
	if (root == nullptr)
		return ;
	vi.push_back(root->data);
	PreOrder(root->left, vi);
	PreOrder(root->right, vi); 
}
void PostOrder(Node *root, vector<int> &vi) {
	if (root == nullptr)
		return ;
	PostOrder(root->left, vi);
	PostOrder(root->right, vi); 
	vi.push_back(root->data);
}
int main() {
	int n = 0;
	scanf("%d", &n);
	Node *root = nullptr;
	Node *mirror = nullptr;
	for (int i = 0;i < n;++i) {
		int e = 0;
		scanf("%d", &e);
		origin.push_back(e);
		InsertNormal(root, e);
		InsertMirror(mirror, e);
	}
	PreOrder(root, normal_pre);
	PreOrder(mirror, mirror_pre);
//	for (auto item : mirror_pre) {
//		cout << item << " ";
//	}
//	cout << endl;
//	for (auto item : normal_pre) {
//		cout << item << " ";
//	}
//	cout << endl;
	if (origin == normal_pre) {
		printf("YES\n");
		PostOrder(root, normal_post);
		int flag = 0;
		for (int i = 0;i < n;++i) {
			if (flag)
				printf(" ");
			flag = 1;
			printf("%d", normal_post[i]);
		}
	}
	else if (origin == mirror_pre) {
		printf("YES\n");
		PostOrder(mirror, mirror_post);
		int flag = 0;
		for (int i = 0;i < n;++i) {
			if (flag)
				printf(" ");
			flag = 1;
			printf("%d", mirror_post[i]);
		}
	} 
	else
		printf("NO\n");
	return 0;
} 
