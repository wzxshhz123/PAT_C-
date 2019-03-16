#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
using namespace std;
constexpr int max_n = 100005;
vector<int> v[max_n];
int main() {
	int n = 0;
	int m = 0;
	scanf("%d %d", &n, &m);
	set<pair<int, int>> relation;
	auto Cmp = [](const pair<int, int> &lhs, const pair<int, int> &rhs) {
		if (lhs.first != rhs.first) 
			return lhs.first < rhs.first;
		return lhs.second < rhs.second;
	};
	set<pair<int, int>, decltype(Cmp)> res(Cmp);
	for (int i = 0;i < m;++i) {
		string lhs;
		string rhs;
		cin >> lhs >> rhs; 
		int a = abs(stoi(lhs));
		int b = abs(stoi(rhs));
		if (lhs.length() == rhs.length()) {
			v[a].push_back(b);
			v[b].push_back(a);
		}
		relation.emplace(a, b);
		relation.emplace(b, a);
	}
	int k = 0;
	scanf("%d", &k);
	while (k--) {
		res.clear();
		int a = 0;
		int b = 0;
		scanf("%d %d", &a, &b);
		a = abs(a);
		b = abs(b);
		for (int i = 0;i < v[a].size();++i) {
			if (v[a][i] == b)
				continue;
			int c = v[a][i];
			for (int j = 0;j < v[b].size();++j) {
				if (v[b][j] == a)
					continue;
				int d = v[b][j];
				if (relation.find(make_pair(c, d)) != relation.end()) {
					res.emplace(c, d);
				}
			}
		}
		printf("%d\n", res.size());
		for (auto iter = res.begin();iter != res.end();++iter) {
			printf("%04d %04d\n", iter->first, iter->second);
		}
	}
	return 0;
}
