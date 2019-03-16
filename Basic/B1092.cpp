#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
int n = 0;
int m = 0;
int main() {
	scanf("%d %d", &n, &m);
	vector<int>vec(n);
	for (int i = 0;i < m;++i) {
		for (int j = 0;j < n;++j) {
			int e = 0;
			scanf("%d", &e);
			vec[j] += e;
		}
	}
	auto max_pos = max_element(vec.begin(), vec.end());
	int max = vec[distance(vec.begin(), max_pos)];
	int flag = 0;
	cout << max << '\n';
	for (int i = 0;i < vec.size();++i) {
		if (vec[i] == max) {
			if (flag)
				printf(" ");
			flag = 1;
			printf("%d", i + 1);
		}
	}
	return 0;
}
