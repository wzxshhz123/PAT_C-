#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
	int n = 0;
	long long p = 0;
	scanf("%d %lld", &n, &p);
	int ns = n;
	vector<long long> vec;
	while (n--) {
		long long e = 0;
		scanf("%lld", &e);
		vec.push_back(e);
	}
	sort(vec.begin(), vec.end());
	int max = -1;
	for (int i = 0;i < vec.size();++i) {
		long long num = vec[i] * p;
		auto iter = upper_bound(vec.begin() + i + 1, vec.end(), num);
		int size = (iter - vec.begin() - i);
		if (size > max) {
			max = size;
		}
	}
	cout << max;

	return 0;
}
