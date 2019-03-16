#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
constexpr int max_v = 505;
struct Node {
	int v = -1;
	int dis = -1;
};
vector<Node>adj[max_v];
vector<int>pre[max_v];
int d[max_v];
bool vis[max_v];
int cost[max_v][max_v] = {0};
int n = -1;
int m = -1;
int st = -1;
int ed = -1;
void Dis(int s) {
	fill(d, d + max_v, INT_MAX);
	d[s] = 0;
	for (int i = 0;i < n;++i) {
		int u = 1;
		int min = INT_MAX;
		for (int j = 0;j < n;++j) {
			if (vis[j] == false && d[j] < min) {
				u = j;
				min = d[j];
			}
		}
		if (u == -1)
			return ;
		vis[u] = true;
		for (int j = 0;j < adj[u].size();++j) {
			int v = adj[u][j].v;
			if (vis[v] == false && adj[u][j].dis != -1) {
				if (d[u] + adj[u][j].dis < d[v]) {
					d[v] = d[u] + adj[u][j].dis;
					pre[v].clear();
					pre[v].push_back(u);
				}
				else if (d[u] + adj[u][j].dis == d[v]) {
					pre[v].push_back(u);
				}
			}
		}
	}
}
vector<int>path, temp_path;
int best_value = INT_MAX;
void DFS(int v) {
	if (v == st) {
		temp_path.push_back(v);
		int value = 0;
		for (int i = temp_path.size() - 1;i > 0;--i) {
			int id = temp_path[i];
			int next = temp_path[i - 1];
			value += cost[id][next];
		}
		if (value < best_value) {
			best_value = value;
			path = temp_path;
		}
		temp_path.pop_back();
		return ; 
	}
	temp_path.push_back(v);
	for (int i = 0;i < pre[v].size();++i) {
		DFS(pre[v][i]);
	}
	temp_path.pop_back();
}
int main() {
	scanf("%d %d %d %d", &n, &m, &st, &ed);
	for (int i = 0;i < m;++i) {
		int u = -1;
		int v = -1;
		int dis = -1;
		int c = -1;
		scanf("%d %d %d %d", &u, &v, &dis, &c);
		Node ins;
		ins.dis = dis;
		ins.v = v;
		adj[u].push_back(ins);
		ins.v = u;
		adj[v].push_back(ins);
		cost[u][v] = c;
		cost[v][u] = c;
	}
	Dis(st);
	DFS(ed);
	for (auto riter = path.rbegin();riter != path.rend();++riter) {
		printf("%d ", *riter);
	}
	printf("%d %d", d[ed], best_value);
	return 0;
}
