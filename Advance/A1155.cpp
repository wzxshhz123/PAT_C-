#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Node {
	int data = -1;
	int l_child = -1;
	int r_child = -1;	
};
vector<Node> tree(1005);
vector<int> origin;
int n = 0;
int index = 0;
void Create(int root) {
	tree[root].data = origin[root];
	if (root * 2 <= n) 
		tree[root].l_child = root * 2;
	if (root * 2 + 1 <= n)
		tree[root].r_child = root * 2 + 1;
	if (tree[root].l_child != -1)
		Create(tree[root].l_child);
	if (tree[root].r_child != -1)
		Create(tree[root].r_child);
}
void DFS(vector<Node> &path, int root) {
	if (path.back().l_child == -1 && path.back().r_child == -1) {
		int flag = 0;
		for (auto iter = path.begin();iter != path.end();++iter) {
			if (flag)
				printf(" ");
			flag = 1;
			printf("%d", iter->data);
		}
		printf("\n");
		return ;
	}
	else 
		if (tree[root].r_child != -1) {
			path.push_back(tree[tree[root].r_child]);
			DFS(path, tree[root].r_child);
			path.pop_back();
		}
		if (tree[root].l_child != -1) {
			path.push_back(tree[tree[root].l_child]);
			DFS(path, tree[root].l_child);
			path.pop_back();
		}
}
int main() {
	scanf("%d", &n);
	origin.push_back(-1);
	for (int i = 0;i < n;++i) {
		int e = 0;
		scanf("%d", &e);
		origin.push_back(e);
	}
  Create(1);
	vector<Node> path;
	path.push_back(tree[1]);
	DFS(path, 1);
	origin.erase(origin.begin());
	vector<int>temp = origin;
	bool is_max_heap = true;
	bool is_min_heap = false;
	make_heap(origin.begin(), origin.end());
	for (int i = 0;i < n;++i) {
		if (temp[i] != origin[i]) {
			is_max_heap = false;
			break;
		}
	}
	if (!is_max_heap) {
		is_min_heap = true;
		auto Cmp = [](const int &lhs, const int &rhs) {
			return lhs > rhs;
		};
		make_heap(origin.begin(), origin.end(), Cmp);
		for (int i = 0;i < n;++i) {
			if (temp[i] != origin[i]) {
				is_min_heap = false;
				break;
			}
		}
	}
	if (!is_max_heap && !is_min_heap) {
		printf("Not Heap\n");
	}
	else if (is_max_heap && !is_min_heap) {
		printf("Max Heap\n");
	}
	else if (!is_max_heap && is_min_heap) {
		printf("Min Heap\n");
	}
	return 0;
}
 
