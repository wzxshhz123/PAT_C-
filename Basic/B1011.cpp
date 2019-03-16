#include <cstdio>
using namespace std;
int main() {
	int num = 0;
	scanf("%d",&num);
	int n = 1;
	while(num--) {
		long long a = 0;
		long long b = 0;
		long long c = 0;
		scanf("%ld %ld %ld",&a,&b,&c);
		if(a + b > c) {
			n != 1 ? printf("\n") : printf("");
			printf("Case #%d: true",n);
		}
		else {
			n != 1 ? printf("\n") : printf("");
			printf("Case #%d: false",n);
		}
		++n;
	}
	return 0;
} 
