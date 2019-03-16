#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Node {
	int data = -1;
	vector<int>child;
};
int n = -1;
int m = -1;
int max_depth = -1;
vector<Node>vec(101);
vector<int>num(101);
void DFS(int index, int depth) {
	if (vec[index].child.size() == 0) {
		++num[depth];
		max_depth = max(max_depth, depth);
		return ;
	}
	for (int i = 0;i < vec[index].child.size();++i)
		DFS(vec[index].child[i], depth + 1);
}
int main() {
	scanf("%d %d", &n, &m);
	if (n == 0)
		return 0;
	for (int i = 0;i < m;++i) {
		int id = 0;
		int size = 0;
		scanf("%d %d", &id, &size);
		for (int j = 0;j < size;++j) {
			int e = 0;
			scanf("%d", &e);
			vec[id].child.push_back(e);
		}
	}
	DFS(1, 0);
	int flag = 0;
	for (int i = 0;i <= max_depth;++i) {
		if (flag)
			printf(" ");
		flag = 1;
		printf("%d", num[i]);
	}
	return 0;
}
