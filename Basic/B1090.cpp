#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std; 
int main() {
	int n = 0;
	int m = 0;
	unordered_map<int, vector<int>> map;
	scanf("%d %d", &n, &m);
	for (int i = 0;i < n;++i) {
		int a = 0;
		int b = 0;
		scanf("%d %d", &a, &b);
		map[a].push_back(b);
		map[b].push_back(a);
	}
	for (int i = 0;i < m;++i) {
		int size = 0;
		scanf("%d", &size);
		int f = 1;
		vector<int>vec;
		for (int j = 0;j < size;++j) {
			int e = 0;
			scanf("%d", &e);
			vec.push_back(e);
		}
		for (int j = 0;j < vec.size();++j) {
//			int a = vec[j];
			for (auto iter = map[vec[j]].begin();iter != map[vec[j]].end();++iter) {
				int e = *iter;
				if (find(vec.begin(), vec.end(), e) != vec.end()) {
					f = 0;
					break;
				}
			}
			if (!f) 
				break;
		}
		if (f) {
			printf("Yes\n");
		}
		else {
			printf("No\n");
		}
	}
	return 0;
}
