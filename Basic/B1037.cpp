#include <cstdio>
#include <cmath>
using namespace std;
int main() {
	int n = 2;
	int sum[2] = {0};
	while (n--) {
		int a = 0;
		int b = 0;
		int c = 0;
		scanf("%d.%d.%d",&a,&b,&c);
		b += a * 17;
		c += b * 29;
		sum[n] = c;
	}
//	printf("%d %d\n",sum[0],sum[1]);
	int minus = sum[0] - sum[1];
//	printf("%d\n",minus);
  if (minus < 0){
  	
	 printf("%d.%d.%d",minus / 493),abs(minus % 493 / 29),abs(minus % 29));
  }
	else if (minus >= 0)
	   printf("%d.%d.%d",minus / 493,minus % 493 / 29, minus % 29);
  return 0;
}
