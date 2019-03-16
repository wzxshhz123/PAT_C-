#include <iostream>
#include <vector>
#include <algorithm> 
#include <map>
#include <utility>
using namespace std;
int main() {
	int n = 0;
	int target = 0;
	scanf("%d %d", &n, &target);
	vector<int> vec;
	map<int, int>m;
	pair<int, int>p{-1, -1};
	while (n--) {
		int e = 0;
		scanf("%d", &e);
		vec.push_back(e);
		++m[e];
	}
	sort(vec.begin(), vec.end());
	for (auto iter = vec.begin();iter != vec.end();++iter) {
		int t = target - *iter;
		if (t != *iter) {
			if (m.count(t) != 0) {
				p = make_pair(*iter, t);
				break;
			}
		}
		else if (t == *iter) {
			if (m[*iter] > 1) {
				p = make_pair(*iter, t);
				break;
			}
		}
	}
	if (p.first != -1) {
		printf("%d %d", p.first, p.second);
	}
	else {
		printf("No Solution");
	}
	return 0;
}
