#include <iostream>
#include <algorithm> 
using namespace std;
int main() {
	int n = 0;
	int target = 0;
	scanf("%d %d", &n, &target);
	int ns = n;
	vector<int> vec;
	while (n--) {
		int e = 0;
		scanf("%d", &e);
		vec.push_back(e);
		++m[e];
	}
	sort(vec.begin(), vec.end());
		auto i = 0;
		auto j = ns - 1;
		while (i < j) {
			if (vec[i] + vec[j] == target) {
				printf("%d %d", vec[i], vec[j]);
				return 0;
			}
			else if (vec[i] + vec[j] > target) {
				--j;
			}
			else if (vec[i] + vec[j] < target) {
				++i;
			}
		}
	printf("No Solution");
	return 0;
}


