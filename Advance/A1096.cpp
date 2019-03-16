#include <iostream>
#include <cmath>
using namespace std;
int main() {
	long long num = 0;
	scanf("%lld", &num);
	long long begin = 0;
	long long len = 0;
	long long sqr = sqrt(num);
	for (int i = 2;i <= sqr;++i) {
		long long temp = 1;
		long long j = i;
		while (true) {
			temp *= j;
			if (num % temp != 0)
				break;
			if (j - i + 1 > len) {
				begin = i;
				len = j - i + 1;
			}
			++j;
		}
	}
	if (len == 0) {
		printf("1\n%lld", num);
	}
	printf("%lld\n", len);
	int flag = 0;
	for (int i = 0;i < len;++i) {
		if (flag)
			printf("*");
		flag = 1;
		printf("%lld", begin);
		++begin;
	}
	return 0;
} 
