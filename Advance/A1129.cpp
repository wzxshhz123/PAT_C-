#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
using namespace std;
struct Node {
	int data = -1;
	int times = -1;
	Node(int d_, int t_) : data(d_), times(t_) {
		
	}
};
int main() {
	int n = 0;
	int k = 0;
	auto Cmp = [](const Node &lhs, const Node &rhs) {
		if (lhs.times != rhs.times)
			return lhs.times > rhs.times;
		return lhs.data < rhs.data;
	};
	scanf("%d %d", &n, &k);
	set<Node, decltype(Cmp)> s(Cmp);
	unordered_map<int, int> index_to_num; 
	int f = 0;
	for (int i = 0;i < n;++i) {
		if (i == 0) {
			int e = 0;
			scanf("%d", &e);
			s.emplace(e, 1);
			++index_to_num[e];
			continue;
		}
		int e = 0;
		scanf("%d", &e);
		if (f)
			printf("\n");
		f = 1;
		printf("%d:", e);
		int num = 0;
		for (auto iter = s.begin();iter != s.end() && num < k;++iter, ++num) {
			printf(" %d", iter->data);
		}
		auto it = s.find(Node(e, index_to_num[e]));
		if (it != s.end())
			s.erase(it);
		++index_to_num[e];
		s.emplace(e, index_to_num[e]);
	}
	return 0;
}
