#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
constexpr int max_v = 1015;
struct Node {
	int v = -1;
	int dis = -1;
};
vector<Node>adj[max_v];
int d[max_v];
bool vis[max_v] = {0}; 
int n = -1;
int m = -1;
int k = -1;
int ds = -1;
void Dis(int s) {
	fill(d, d + max_v, INT_MAX);
	fill(vis, vis + max_v, false);
	d[s] = 0;
	for (int i = 1;i <= n + m;++i) {
		int u = -1;
		int min = INT_MAX;
		for (int j = 1;j <= n + m;++j) {
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
				}
			}
		}
	}
}
int main() {
	scanf("%d %d %d %d", &n, &m, &k, &ds);
	for (int i = 1;i <= k;++i) {
		string str_1;
		string str_2;
		int dis = -1;
		cin >> str_1 >> str_2;
		scanf("%d", &dis);
		int u = -1;
		int v = -1;
		if(str_1[0] == 'G') {
			str_1.erase(str_1.begin());
			u = stoi(str_1) + n;
		}
		else {
			u = stoi(str_1);
		}
		if (str_2[0] == 'G') {
			str_2.erase(str_2.begin());
			v = stoi(str_2) + n;
		}
		else {
			v = stoi(str_2);
		}
		Node ins;
		ins.dis = dis;
		ins.v = v;
		adj[u].push_back(ins);
		ins.v = u;
		adj[v].push_back(ins);
	}
	double ans_avg = INT_MAX;
	int ans_id = -1;
	double ans_dis = -1;
	for (int i = 1;i <= m;++i) {
		Dis(n + i);
//		printf("%d ", d[n]);
		double min_dis = INT_MAX;
		double avg = 0;
		for (int j = 1;j <= n;++j) {
			if (d[j] > ds) {
				min_dis = -1;
				break;
			}
			if (d[j] < min_dis)
				min_dis = d[j];
			avg += 1.0 * d[j] / n;
		}
		if (min_dis == -1)
			continue;
		if (min_dis > ans_dis) {
			ans_dis = min_dis;
			ans_avg = avg;
			ans_id = i;
		}
		else if (min_dis == ans_dis && avg < ans_avg) {
			ans_dis = min_dis;
			ans_avg = avg;
			ans_id = i;
		}
	}
	if (ans_id == -1)
		printf("No Solution");
	else {
		printf("G%d\n", ans_id);
		printf("%.1lf %.1lf", ans_dis, ans_avg);
	}
	return 0;
}
