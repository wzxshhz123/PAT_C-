#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;
struct Node {
	int v = -1;
	int dis = 0;
};
constexpr int max_v = 505;
vector<Node>adj[max_v];
int st = -1;
int ed = -1;
bool vis[max_v] = {0};
int d[max_v];
int weight[max_v] = {0};
int w[max_v] = {0};
int num[max_v] = {0};
int n = 0;
int m = 0;
void Dis(int s) {
	fill(d, d + max_v, INT_MAX);
//	fill(num, num + max_v, 0);
//	fill(w, w + max_v, 0);
	d[s] = 0;
	w[s] = weight[s];
	num[s] = 1;
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
			if (vis[v] == false && d[u] + adj[u][j].dis != INT_MAX) {
				if (d[u] + adj[u][j].dis < d[v]) {
					d[v] = d[u] + adj[u][j].dis;
					w[v] = w[u] + weight[v];
					num[v] = num[u];
				}
				else if (d[u] + adj[u][j].dis == d[v]) {
					if (w[u] + weight[v] > w[v]) {
						w[v] = w[u] + weight[v];
					}
					num[v] += num[u];
				}
			}
		
		}
		
	}
}
int main() {
	scanf("%d %d %d %d", &n, &m, &st, &ed);
	for (int i = 0;i < n;++i) {
		int e = 0;
		scanf("%d", &e);
		weight[i] = e;
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
	printf("%d %d\n", num[ed], w[ed]);
	return 0; 
} 
