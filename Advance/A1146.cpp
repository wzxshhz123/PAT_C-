#include <iostream>
#include <vector>
using namespace std;
constexpr int max_n = 1005;
vector<int> adj[max_n];
vector<int> degree(max_n);
int n = 0;
int m = 0;
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0;i < m;++i) {
		int a = 0;
		int b = 0;
		scanf("%d %d", &a, &b);
		adj[a].push_back(b);
		++degree[b];
	}
	int k = 0;
	scanf("%d", &k);
	int flag = 0;
	vector<int> res;
	for (int i = 0;i < k;++i) {
		int f = 1;
		auto temp = degree;
		for (int j = 0;j < n;++j) {
			int e = 0;
			scanf("%d", &e);
			if (degree[e] != 0) {
				f = 0;
			}
			else {
				for (int q = 0;q < adj[e].size();++q) {
					--degree[adj[e][q]];
				}
			}
		}
		if (!f) {
			res.push_back(i);
		}
		degree = temp;
	}
	for (auto iter = res.begin();iter != res.end();++iter) {
		if (flag)
			printf(" ");
		flag = 1;
		printf("%d", *iter);
	}
	return 0;
} 
