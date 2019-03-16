#include <iostream>
#include <vector>
using namespace std;
constexpr int maxn = 1000000;
bool p[maxn] = {false};
vector<int> prime;
void FindPrime(int n) {
	for (int i = 2;i < maxn;++i) {
		if (p[i] == false) {
			prime.push_back(i);
			if (prime.size() >= n)
				break;
			for (int j = i + i;j < maxn;j += i) {
				if (j % i == 0) {
					p[j] = true;
				}
			}
		}
	}
}
int main() {
	int m = 0;
	int n = 0;
	scanf("%d %d", &m, &n);
	FindPrime(n);
	int count = 0;
	int flag = 0;
	for (int i = m;i <= n; ++i) {
		if (flag)
			printf(" ");
		flag = 1;
		printf("%d", prime[i - 1]);
		++count;
		if (count % 10 == 0) {
			printf("\n");
			flag = 0;
		}
			
	}
	return 0;
}

