#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;
int main() {
	int n = 0;
	scanf("%d", &n);
	vector<int>vec;
	unordered_map<int, bool> m;
	for (int i = 0;i < n;++i) {
		int e = 0;
		scanf("%d", &e);
		if (e > 0 && m[e] == false) {
			vec.push_back(e);
			m[e] = true;
		}
	} 
	if (vec.size() != 0) {
		sort(vec.begin(), vec.end());
		auto min_v = *min_element(vec.begin(), vec.end());
		for (auto iter = vec.begin();iter != vec.end();++iter) {
			if (min_v != *iter) {
				break;
			}
			++min_v;
		}
		printf("%d", min_v);
	}
	else {
		printf("1");
	}
	return 0;

}
