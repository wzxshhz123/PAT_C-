#include <iostream>
#include <set>
#include <unordered_map>
using namespace std;
int main() {
	int n = 0;
	int m = 0;
	scanf("%d %d", &n, &m);
	set<pair<int, int>> edges;
	for (int i = 0;i < m;++i) {
		int a = 0;
		int b = 0;
		scanf("%d %d", &a, &b);
		edges.emplace(a, b);
//		edges.emplace(b, a);
	}
	int k = 0;
	scanf("%d", &k);
	while (k--) {
		unordered_map<int, bool> mp;
		int size = 0;
		scanf("%d", &size);
		for (int i = 0;i < size;++i) {
			int e = 0;
			scanf("%d", &e);
			mp[e] = true;
		}	
		int f = 1;
		for (auto iter = edges.begin();iter != edges.end();++iter) {
			if (mp.count(iter->first) == 0 && mp.count(iter->second) == 0) {
				f = 0;
				break;
			}
		}
		if (f)
			printf("Yes\n");
		else
			printf("No\n");
	}
}
