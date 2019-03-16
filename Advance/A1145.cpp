#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
bool IsPrime(int n) {
	if (n <= 1)
		return false;
	int num = (int)sqrt(1.0 * n);
	for (int i = 2;i <= num;++i) {
		if (n % i == 0)
			return false;
	}
	return true;
}
int msize = 0;
int n = 0;
int m = 0;
int main() {
	scanf("%d %d %d", &msize, &n, &m);
	while (!IsPrime(msize)) {
		++msize;
	}
	vector<int>vec(msize);
	vec.shrink_to_fit();
	for (int i = 0;i < n;++i) {
		int e = 0;
		scanf("%d", &e);
		int temp = 0;
		for (int j = 0;j <= msize;++j) {
			temp = (e + j * j) % msize;
			if (vec[temp] == 0)
				break;
		}
		if (vec[temp] == 0) {
			vec[temp] = e;
		}
		else {
			printf("%d cannot be inserted.\n", e);
		}
	}
	double time = 0;
	for (int i = 0;i < m;++i) {
		int q = 0;
		scanf("%d", &q);
		int temp = 0;
		for (int j = 0;j <= msize;++j) {
			++time;
			temp = (q + j * j) % msize;
			if (vec[temp] == q || vec[temp] == 0) {
				break;
			}
		}
	}
	printf("%.1lf", time / m);
}
