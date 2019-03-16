#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int n = 0;
	scanf("%d", &n);
//	vector<unordered_set<int>> vec;
	unordered_set<int> vec[50];
	int i = 0; 
	while (n--) {
		int num = 0;
		scanf("%d", &num);
//		unordered_set<int>temp;
		while (num--) {
			int v = 0;
			scanf("%d", &v);
			vec[i].insert(v);
		}
		++i;
//		vec.push_back(temp);
	}
	int query = 0;
	scanf("%d", &query);
	int flag = 0;
	while (query--) {
		if (flag)
			printf("\n");
		flag = 1;
		int x = 0;
		int y = 0;
		scanf("%d %d", &x, &y);
//		for (auto item : vec[x - 1]) {
//			cout << item << " ";
//		}
//		cout << endl;
//		for (auto item :vec[y - 1]) {
//			cout << item << " ";
//		}
//		cout << endl;
//		float total = vec[x - 1].size() + vec[y - 1].size();
		float m = 0.f;
		float total = vec[y - 1].size();
		for (auto iter = vec[x - 1].begin();iter != vec[x - 1].end();++iter) {
			if (vec[y - 1].count(*iter) == 1)
				++m;
			else
				++total;	
		}
		printf("%.1lf%%", m / total * 100);
	}
	return 0;
} 
