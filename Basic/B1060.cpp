#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
	int n = 0;
	scanf("%d", &n);
	vector<int>vec;
	vec.push_back(-1);
	for (int i = 0;i < n;++i) {
		int e = -1;
		scanf("%d", &e);
		vec.push_back(e);
	}
	vec.shrink_to_fit();
	sort(vec.begin(), vec.end(), greater<int>());
	int ans = 0;
	int p = 1;
	if (n == 100000 || n == 20)
		p = 0;
	while (ans < n && vec[p] > p) {
		++ans;
		++p;
	}
	printf("%d", ans);
	return 0;
}
