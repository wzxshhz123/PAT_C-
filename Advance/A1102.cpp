#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
constexpr int maxn = 10;
struct Node {
	int data = -1;
	int l_child = -1;
	int r_child = -1;
}; 
bool isNotRoot[maxn] = {false};
vector<Node>vec;
int flag = 0;
void BFS(int index) {
	queue<int>q;
	q.push(index);
	while(!q.empty()) {
		int i = q.front();
		q.pop();
		if (vec[i].l_child != -1)
			q.push(vec[i].l_child);
		if (vec[i].r_child != -1)
			q.push(vec[i].r_child);
		if (flag)
			printf(" ");
		flag = 1;
		printf("%d", vec[i].data);
	}
}
void Inorder(int index) {
	Node e = vec[index];
	if (e.data == -1)
		return ;
	if (e.l_child != -1)
		Inorder(e.l_child);
	if (flag)
		printf(" ");
	flag = 1;
	printf("%d", e.data);
	if (e.r_child != -1)
		Inorder(e.r_child);
}
void Reverse(int index) {
	Node e = vec[index];
	if (e.data == -1)
		return ;
	if (e.l_child != -1)
		Reverse(e.l_child);
	if (e.r_child != -1)
		Reverse(e.r_child);
	swap(vec[index].l_child, vec[index].r_child);
}
int main() {
	int n = 0;
	scanf("%d", &n);
	getchar();
	for (int i = 0;i < n;++i) {
		string str;
		getline(cin, str);
		Node root;
		root.data = i;
		if (isdigit(str[0])) {
			int e = str[0] - '0';
			root.l_child = e;
			isNotRoot[e] = true;
		}
		if (isdigit(str[2])) {
			int e = str[2] - '0';
			root.r_child = e; 
			isNotRoot[e] = true;
		}
		vec.push_back(root);
	}
	int k = 0;
	for (;k < n;++k) {
		if (isNotRoot[k] == false)
			break;
	}
	Reverse(k);
	BFS(k);
	flag = 0;
	printf("\n");
	Inorder(k);
	return 0;
}
