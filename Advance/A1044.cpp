#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;
int main() {
	long long n = 0;
	long long target = 0;
	scanf("%lld %lld", &n, &target);
	long long temp = 0;
	vector<int>sum;
	sum.push_back(0);
	while (n--) {
		int e = 0;
		scanf("%d", &e);
		temp += e;
		sum.push_back(temp);
	}
	long long near = INT_MAX;
	for (int i = 1;i < sum.size();++i) {
		long long num = sum[i - 1];
		auto iter = upper_bound(sum.begin() + i, sum.end(), target + num);
		if (*(iter - 1) - num == target) {
				near = target;
				break;
		}
		else if (iter != sum.end() && *iter - num < near) {
				near = *iter - num;
			}
		}
	int flag = 0;
	for (int i = 1;i < sum.size();++i) {
		long long num = sum[i - 1];
		auto iter = upper_bound(sum.begin() + i, sum.end(), near + num);
		if (*(iter - 1) - num == near) {
			if (flag)
				printf("\n");
			flag = 1;
			printf("%d-%d", i, iter - 1 - sum.begin());
		}
	}
	return 0;
}
