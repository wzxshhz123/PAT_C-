#include <iostream>
#include <vector>
using namespace std;
int main() {
	int n = 0;
	scanf("%d", &n);
	vector<int> vec;
	vec.push_back(0);
	for (int i = 1;i <= n;++i) {
		int e = 0;
		scanf("%d", &e);
		vec.push_back(e);
	}
	for (int i = 1;i <= n;++i) {
		for (int j = i + 1;j <= n;++j) {
			if (i == 1 && j == 4) {
				printf("");
			}
			vector<int>lie;
			vector<int>temp(n + 1, 1);
			temp[i] = -1;
			temp[j] = -1;
			for (int k = 1;k <= n;++k) {
				if (vec[k] * temp[abs(vec[k])] < 0)
					lie.push_back(k);
			}
			if (lie.size() == 2 && temp[lie[0]] * temp[lie[1]] == -1) {
				printf("%d %d", i, j);
				return 0;
			}
		}
	}
	printf("No Solution");
	return 0;
} 
