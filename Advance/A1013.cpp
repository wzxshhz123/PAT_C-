#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
constexpr int maxn = 2001;
vector<int>G[maxn];
bool vis[maxn] = {0};
int n = 0;
int m = 0;
int k = 0;
void DFS(int index, const int &query) {
	if (index == query)
		return ;
	vis[index] = true;
	for (int i = 0;i < G[index].size();++i) {
		if (vis[G[index][i]] == false)
			DFS(G[index][i], query); 
	}
}
int main() {
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0;i < m;++i) {
		int id1 = 0;
		int id2 = 0;
		scanf("%d %d", &id1, &id2);
		G[id1].push_back(id2);
		G[id2].push_back(id1);
	}
	int flag = 0;
	for (int i = 0;i < k;++i) {
		int query = 0;
		int block = 0;
		scanf("%d", &query);
		fill(vis, vis + maxn, false);
		for (int j = 1;j <= n;++j) {
			if (j != query && vis[j] == false) {
				DFS(j, query);
				++block;
			}
		}
		if (flag)
			printf("\n");
		flag = 1;
		printf("%d", block - 1);
	}
	return 0;
}
