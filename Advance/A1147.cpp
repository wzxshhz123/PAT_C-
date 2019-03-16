#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Node {
	int data = -1;
	int l_child = -1;
	int r_child = -1;
};
int n = 0;
int size = 0;
vector<int>data;
vector<Node> tree(1005);
void Create(int root) {
	tree[root].data = data[root];
	if (root * 2 <= size)
		tree[root].l_child = root * 2;
	if (root * 2 + 1 <= size)
		tree[root].r_child = root * 2 + 1;
	if (tree[root].l_child != -1)
		Create(tree[root].l_child);
	if (tree[root].r_child != -1)
		Create(tree[root].r_child);
}
int flag = 0;
void PostOrder(int root) {
	if (root == -1)
		return ;
	PostOrder(tree[root].l_child);
	PostOrder(tree[root].r_child);
	if (flag)
		printf(" ");
	flag = 1;
	printf("%d", tree[root].data);
}
int main() {
	scanf("%d %d", &n, &size);
	for (int i = 0;i < n;++i) {
		vector<int> vec;
		data.clear();
		tree.clear();
		flag = 0;
		data.push_back(0);
		for (int j = 0;j < size;++j) {
			int e = 0;
			scanf("%d", &e);
			vec.push_back(e);
			data.push_back(e);
		}
		auto origin = vec;
		int through_min = 0;
		make_heap(vec.begin(), vec.end());
		int f = 1;
		for (int j = 0;j < size;++j) {
			if (vec[j] != origin[j]) {
				f = 0;
				break;
			}
		}
		if (f) {
			printf("Max Heap\n");
		}
		else {
			f = 1;
			through_min = 1;
			auto Cmp = [](const int &a, const int &b) {
				return a > b;
			};
			make_heap(vec.begin(), vec.end(), Cmp);
			for (int j = 0;j < size;++j) {
				if (vec[j] != origin[j]) {
					f = 0;
					break;
				}
			}
		}
		if (f && through_min) {
			printf("Min Heap\n");
		}
		if (!f) {
			printf("Not Heap\n");
		}
		Create(1);
		PostOrder(1);
		printf("\n");
	}
} 
