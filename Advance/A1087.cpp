#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <unordered_map>
using namespace std;
struct Node {
	int v = -1;
	string name;
	int dis = -1;
};
constexpr int max_v = 205;
unordered_map<string, int>map;
unordered_map<int, string>itos;
vector<Node>adj[max_v];
int d[max_v];
bool vis[max_v] = {0};
int weight[max_v] = {0};
int n = -1;
int m = -1;
int st = 0;
int ed = -1;
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
			if (vis[v] == false)
				if(d[u] + adj[u][j].dis < d[v]) {
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
int num = 0;
int max_happy = 0;
double avg_happy = 0;
vector<int>temp_path, path;
void DFS(int v) {
	if (v == st) {
		temp_path.push_back(v);
		int happy = 0;
		double avg = 0;
//		
//		for (auto riter = temp_path.rbegin();riter != temp_path.rend();++riter) {
//			printf("%d ", *riter);
//		}
//		printf("\n");
		for (int i = 0;i < temp_path.size();++i) {
			happy += weight[temp_path[i]];
		}
		avg = 1.0 * happy / (temp_path.size() - 1);
		if (happy > max_happy) {
			max_happy = happy;
			avg_happy = avg;
			path = temp_path;
		}
		else if (happy == max_happy && avg > avg_happy) {
			avg_happy = avg;
			path = temp_path;
		}
		temp_path.pop_back();
		++num;
		return ;
	}
	temp_path.push_back(v);
	for (int i = 0;i < pre[v].size();++i)
		DFS(pre[v][i]);
	temp_path.pop_back();
}
int main() {
	scanf("%d %d", &n, &m);
	string s;
	cin >> s;
	map[s] = 0;
	itos[0] = s;
	ed = n - 1;
	int t = 0;
	for (int i = 1;i < n;++i) {
		string str;
		int w = -1;
		cin >> str;
		scanf("%d", &w);
		if (str == "ROM") {
			t = i;
			map[str] = ed;
			weight[ed] = w;
			itos[ed] = str;
			continue;
		}
		else {
			if (i == ed) {
				map[str] = t;
				weight[t] = w;
				itos[t] = str;
			}
			else {
				map[str] = i;
				weight[i] = w;
				itos[i] = str;
			}
		}
	
	}
	for (int i = 0;i < m;++i) {
		Node ins;
		string str_1;
		string str_2;
		int dis = -1;
		cin >> str_1 >> str_2;
		scanf("%d", &dis);	
		ins.dis = dis;
		ins.name = str_2;
		ins.v = map[str_2];
		adj[map[str_1]].push_back(ins);
		
		ins.name = str_1;
		ins.v = map[str_1];
		adj[map[str_2]].push_back(ins);
	}
	Dis(st);
	DFS(ed);
	printf("%d %d %d %d\n", num, d[ed], max_happy, (int)avg_happy);
	int flag = 0;
	for (auto riter = path.rbegin();riter != path.rend();++riter) {
		if (flag)
			printf("->");
		flag = 1;
		printf("%s", itos[*riter].c_str());
	}
	return 0;
}
