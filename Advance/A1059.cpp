#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
constexpr int maxn = 100005;
bool p[maxn] = {0};
vector<int>prime;
struct Factor {
	int x = 0;
	int num = 0;
};
void Prime() {
	for (int i = 2;i < maxn;++i) {
		if (p[i] == false) {
			prime.push_back(i);
			for (int j = i + i;j < maxn;j += i) {
				p[j] = true;
			}
		}
	}
}
int main() {
	Prime();
	int n = 0;
	scanf("%d", &n);
//	for (int i = 0;i < 20;++i)  {
//		cout << prime[i] << " "; 
//	} 
	if (n == 1) {
		printf("1=1");
		return 0;
	}
	printf("%d=", n);
	vector<Factor>factor;
	int sqr = sqrt(n);
	for (int i = 0;i < prime.size() && prime[i] <= sqr;++i) {
		if (n % prime[i] == 0) {
			Factor e;
			e.x = prime[i];
			e.num = 0;
			while (n % prime[i] == 0) {
				++e.num;
				n /= prime[i];
			}
			factor.push_back(e);
		}
		if (n == 1)
			break;
	}
	if (n != 1) {
		Factor e;
		e.x = n;
		e.num = 1;
		factor.push_back(e);
	}
	int flag = 0;
	for (auto item : factor) {
		if (flag)
			printf("*");
		flag = 1;
		printf("%d", item.x);
		if (item.num != 1) {
			printf("^%d", item.num);
		}
	}
	return 0;
}
