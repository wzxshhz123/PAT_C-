#include <cstdio>
#include <cmath>
using namespace std;
int main() {
	int n = 2;
	long long sum[2] = {0};
	while (n--) {
		long long a = 0;
		long long b = 0;
		long long c = 0;
		scanf("%lld.%lld.%lld",&a,&b,&c);
		b += a * 17;
		c += b * 29;
		sum[n] = c;
	}
	long long minus = sum[0] + sum[1];
  printf("%lld.%lld.%lld",minus / 493,minus % 493 / 29, minus % 29);
  return 0;
}

