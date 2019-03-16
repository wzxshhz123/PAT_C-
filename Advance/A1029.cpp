#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int main() {
	int n = 0;
	scanf("%d", &n);
	vector<int>vec;
	for (int i = 0;i < n;++i) {
		int e = 0;
		scanf("%d", &e);
		vec.push_back(e);
	}
	vec.push_back(INT_MAX);
	int m = 0;
	scanf("%d", &m);
	int i = 0;
	int count = 0;
	int middle = (n + m - 1) / 2;
	for (int j = 0;j < m;++j) {
		int e = 0;
		scanf("%d", &e);
		while (vec[i] < e) {
			if (count == middle) {
				printf("%d", vec[i]);
				return 0;
			}
			++count;
			++i;
		}
		if (count == middle)
			printf("%d", e);
		++count;
	}
	while (i < n) {
		if (count == middle) {
			printf("%d", vec[i]);
			return 0;	
		}
		++count;
		++i;
	}
	return 0;
	
}
