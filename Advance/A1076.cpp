#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int n = 0;
int l = 0;
constexpr int maxn = 1010;
struct Node {
	int id = 0;
	int layer = 0;
};
vector<Node>G[maxn];
bool inq[maxn] = {0};
int BFS(int root) {
	int num = 0;
	queue<Node>q;
	Node ins;
	ins.id = root;
	ins.layer = 0;
	q.push(ins);
	inq[ins.id] = true;	
	while (!q.empty()) {
		Node top = q.front();
		q.pop();
		for (int i = 0;i < G[top.id].size();++i) {
			Node next = G[top.id][i];
			next.layer = top.layer + 1;
			if (inq[next.id] == false && next.layer <= l) {
				q.push(next);
				inq[next.id] = true;
				++num;
			}
		}
	}
	return num;
}
int main() {
	scanf("%d %d", &n, &l);
	for (int i = 1;i <= n;++i) {
		Node ins;
		int size = 0;
		scanf("%d", &size);
		for (int j = 1;j <= size;++j) {
			int e = 0;
			scanf("%d", &e);
			ins.id = i;
			G[e].push_back(ins);
		}
	}
	int query = 0;
	scanf("%d", &query);
	int flag = 0;
	for (int i = 0;i < query;++i) {
		int q = 0;
		scanf("%d", &q);
		fill(inq, inq + maxn, false);
		int time = BFS(q);
		if (flag)
			printf("\n");
		flag = 1;
		printf("%d", time);
	}
	return 0;
}
