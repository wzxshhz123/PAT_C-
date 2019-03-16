#include <iostream>
#include <unordered_set>
#include <vector>
#include <utility>
using namespace std;
int main() {
	int n = 0;
	int m = 0;
	scanf("%d %d", &n, &m);
	vector<pair<int, int>> vec;
	for (int i = 0;i < m;++i) {
		int a = 0;
		int b = 0;
		scanf("%d %d", &a, &b);
		vec.push_back(make_pair(a, b));
	}
	int k = 0;
	scanf("%d", &k);
	for (int i = 0;i < k;++i) {
		unordered_set<int> s;
		vector<int> color;
		int flag = 1;
		for (int j = 0;j < n;++j) {
			int e = 0;
			scanf("%d", &e);
			s.insert(e);
			color.push_back(e);
		}
		for (auto iter = vec.begin();iter != vec.end();++iter) {
			if (color[iter->first] == color[iter->second]) {
				flag = 0;
				break;
			}
		}
		if (flag)
			printf("%d-coloring\n", s.size());
		else
			printf("No\n");
	}	
	return 0;
}
 
