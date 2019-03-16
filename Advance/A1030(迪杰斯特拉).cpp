#include <iostream>
#include <algorithm>
#include <vector>
#include <climits> 
using namespace std;
constexpr int max_v = 505;
struct Node {
	int v = -1;
	int dis = -1;
};
vector<Node>adj[max_v];
bool vis[max_v] = {0};
int cost[max_v][max_v] = {0};
int pre[max_v] = {0};
int d[max_v];
int c[max_v];
int n = -1;
int m = -1;
int st = -1;
int ed = -1;
void Dis(int s) {
	fill(d, d + max_v, INT_MAX);
	fill(c, c + max_v, INT_MAX);
//	fill(pre, pre + max_v, INT_MAX);
	c[s] = 0;
	d[s] = 0;
	for (int i = 0;i < n;++i)
		pre[i] = i;
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
			if (vis[v] == false && adj[u][j].dis != -1) {
				if (d[u] + adj[u][j].dis < d[v]) {
					d[v] = d[u] + adj[u][j].dis;
					c[v] = c[u] + cost[u][v];
					pre[v] = u;
				}
				else if (d[u] + adj[u][j].dis == d[v]) {
					if (c[u] + cost[u][v] < c[v]) {
						c[v] = c[u] + cost[u][v];
						pre[v] = u;
					}
				}
			}
		}
	}
}
void Print(int v) {
	if (v == st) {
		printf("%d ", v);
		return ;
	}
	Print(pre[v]);
	printf("%d ", v);
}
int main() {
	scanf("%d %d %d %d", &n, &m, &st, &ed);
	for (int i = 0;i < m;++i) {
		Node ins;
		int u = -1;
		int v = -1;
		int c = -1;
		int dis = -1;
		scanf("%d %d %d %d", &u, &v, &dis, &c);
		ins.v = v;
		ins.dis = dis;
		cost[u][v] = c;
		cost[v][u] = c;
		adj[u].push_back(ins);
		ins.v = u;
		adj[v].push_back(ins);
	}
	Dis(st);
	Print(ed);
	printf("%d %d", d[ed], c[ed]);
	return 0;
}
