#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
int main() {
	unordered_map<int, bool> mp;
	vector<int> pre;
	int n = 0;
	int m = 0;
	scanf("%d %d", &n, &m);
	for (int i = 0;i < m;++i) {
		int e = 0;
		scanf("%d", &e);
		pre.push_back(e);
		mp[e] = true;
	}
	for (int i = 0;i < n;++i) {
		int u = 0;
		int v = 0;
		scanf("%d %d", &u, &v);
		if (mp[u] == 0 && mp[v] == 0) {
			printf("ERROR: %d and %d are not found.\n", u, v);
			continue;
		}
		else if (mp[u] != 0 && mp[v] == 0) {
			printf("ERROR: %d is not found.\n", v);
			continue;
		}
		else if (mp[u] == 0 && mp[v] != 0) {
			printf("ERROR: %d is not found.\n", u);
			continue;
		}
		int res = -1;
		for (int j = 0;j < m;++j) {
			res = pre[j];
			if ((res >= u && res <= v) || (res >= v && res <= u))
				break;
		}
		if (res == v)
			printf("%d is an ancestor of %d.", v, u);
		else if (res == u)
			printf("%d is an ancestor of %d.", u, v);
		else
			printf("LCA of %d and %d is %d.", u, v, res);
		printf("\n");
	}
}
