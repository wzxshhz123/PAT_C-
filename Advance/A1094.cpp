#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Node {
	int data = -1;
	vector<int>child;
};
int n = 0;
int m = 0;
vector<Node>vec(101);
int max_node_num[101] = {0};
void DFS(int index, int depth) {
	Node root = vec[index];
	++max_node_num[depth];
	if (root.child.size() != 0) 
		for (int i = 0;i < root.child.size();++i)
			DFS(root.child[i], depth + 1);
}
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0;i < m;++i) {
		Node ins;
		int id = 0;
		int size = 0;
		scanf("%d %d", &id, &size);
		ins.data = id;
		for (int j = 0;j < size;++j) {
			int e = 0;
			scanf("%d", &e);
			ins.child.push_back(e);
		}
		vec[id] = ins;
	}
	DFS(1, 1);
	int i = -1;
	int max = -1;
	for (int j = 1;j <= n;++j) {
		if (max_node_num[j] > max) {
			max = max_node_num[j];
			i = j;
		}
	}
	printf("%d %d", max, i);
	return 0;
}
