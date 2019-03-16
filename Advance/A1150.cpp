#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;
struct Node {
	int v = -1;
	int w = -1;
};
constexpr int max_n = 205;
vector<Node>adj[max_n];
int n = 0;
int m = 0;
int k = 0;
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1;i <= m;++i) {
		Node ins;
		int a = 0;
		int b = 0;
		int dis = 0;
		scanf("%d %d %d", &a, &b, &dis);
		ins.v = b;
		ins.w = dis;
		adj[a].push_back(ins);
		ins.v = a;
		adj[b].push_back(ins);
	}
	scanf("%d", &k);
	map<int, int> res;
	for (int i = 1;i <= k;++i) {
		int size = 0;
		scanf("%d", &size);
		int vis[max_n] = {0};
		int st = -1;
		scanf("%d", &st);
		int start = st;
		int total_sum = 0;
		int pre = 0;
		int flag = 1;
		for (int j = 1;j < size;++j) {
			int target = 0;
			scanf("%d", &target);
			++vis[target];
			++vis[st];
			if (flag) {
				for (int q = 0;q < adj[st].size();++q) {
					auto node = adj[st][q];
					if (node.v == target) {
						total_sum += node.w;
						flag = 1;
						break;
					}
				}
			if (pre == total_sum)
				flag = 0;
			else {
				pre = total_sum;
				st = target;
			}
		}
	}
		int s = 1;
		if (start != st) {
			s = 0;
		}
		else {
			for (int j = 1;j <= n;++j) {
				if (vis[j] > 2 && j != start)  {
					s = 2;
					break;
				}
				else if (vis[j] < 1) {
					s = 0;
					break;
				}
			}
		}
		
		if (!flag) {
			printf("Path %d: NA (Not a TS cycle)\n", i);
		}
		else if (s == 1) {
			printf("Path %d: %d (TS simple cycle)\n", i, total_sum);
			res[total_sum] = i;
		}
		else if (s == 2) {
			printf("Path %d: %d (TS cycle)\n", i, total_sum);
			res[total_sum] = i;
		}
		else if (s == 0) {
			printf("Path %d: %d (Not a TS cycle)\n", i, total_sum);
		}
	}
	if (res.size() != 0)
		printf("Shortest Dist(%d) = %d", res.begin()->second, res.begin()->first);
	return 0;
}
