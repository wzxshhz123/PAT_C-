#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;
constexpr int max_v = 505;
struct Node {
	int v = -1;
	int dis = -1;
};
vector<Node>adj[max_v];
int d[max_v];
int c_max = -1;
int n = -1;
int st = 0;
int ed = -1;
int m = -1;
int weight[max_v] = {0};
bool vis[max_v] = {0};
vector<int>pre[max_v];
void Dis(int s) {
	fill(d, d + max_v, INT_MAX);
	d[s] = 0;
	for (int i = 0;i < n;++i) {
		int u = -1;
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
			if (vis[v] == false) {
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
vector<int>temp_path, path;
int min_need = INT_MAX;
int min_remain = INT_MAX;
void DFS(int v) {
	if (v == st) {
		temp_path.push_back(v);
		int need = 0;
		int remain = 0;
		for (auto riter = temp_path.rbegin();riter != temp_path.rend();++riter) {
			if (weight[*riter] > 0) {
				remain += weight[*riter];
			}
			else {
				if (remain > abs(weight[*riter])) {
					remain -= abs(weight[*riter]);
				}
				else {
					need += abs(weight[*riter]) - remain;
					remain = 0;
				}
			}
		}
		if (need < min_need) {
			min_need = need;
			min_remain = remain;
			path = temp_path;
		}
		else if (need == min_need && remain < min_remain) {
			min_remain = remain;
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
	scanf("%d %d %d %d", &c_max, &n, &ed, &m);
	for (int i = 1;i <= n;++i) {
		int e = 0;
		scanf("%d", &e);
		weight[i] = e - c_max / 2;
	}
	for (int i = 0;i < m;++i) {
		Node ins;
		int u = -1;
		int v = -1;
		int dis = -1;
		scanf("%d %d %d", &u, &v, &dis);
		ins.dis = dis;
		ins.v = v;
		adj[u].push_back(ins);
		ins.v = u;
		adj[v].push_back(ins);
	}
	Dis(st);
	DFS(ed);
	printf("%d ", min_need);
	int flag = 0;
	for (auto riter = path.rbegin();riter != path.rend();++riter) {
		if (flag)
			printf("->");
		flag = 1;
		printf("%d", *riter);
	}
	printf(" %d", min_remain);
	return 0;
}
