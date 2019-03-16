#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int n = 0;
	long long p = 0;
	vector<long long>vec;
	scanf("%d %lld", &n, &p);  
	while (n--) {
		long long e = 0;
		scanf("%lld", &e);
		vec.push_back(e);
	}
	sort(vec.begin(), vec.end());
	int count = -1;
	int j = 0;
	for (int i = 0;i < vec.size();++i) {
		long long num = vec[i];
//		int j = i;
		while (vec[j] <= num * p && j < vec.size()) {
			count = max(count, j - i + 1);
			++j;
		}
	}
	printf("%d", count);
	return 0;
} 
