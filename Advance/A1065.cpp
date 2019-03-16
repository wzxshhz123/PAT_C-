#include <cstdio>
using namespace std;
int main() {
	int t = 0;
	scanf("%d",&t);
	int count = 1;
	while(t--) {
		long long a = 0;
		long long b = 0;
		long long c = 0;
		scanf("%lld %lld %lld",&a,&b,&c);
		long long sum = a + b;
		if (a > 0 && b > 0) {
			if (sum < 0 || sum > c) {
				printf("Case #%d: true",count);
			}
			else {
				printf("Case #%d: false",count);
			}
		}
		else if (a < 0 && b < 0) {
	      if (sum > 0 && c < 0) {
	      	printf("Case #%d: true",count);
				}
				else {
				  printf("Case #%d: false",count);
				}
		}
		else {
			sum > c ? printf("Case #%d: true",count) : printf("Case #%d: false",count);
		}
		++count;
		t != 0? printf("\n"):printf("");
	}
	return 0;
}
