#include <cstdio>
using namespace std;
int main() {
	int n = 0;
	scanf("%d",&n);
	int a = 0;
	int b = 0;
	while(n--) {
		int a_j = 0;
		int a_h = 0;
		int b_j = 0;
		int b_h = 0;
		scanf("%d %d %d %d",&a_j,&a_h,&b_j,&b_h);
		int sum = a_j + b_j;
		if(a_h == sum && b_h == sum) {
			continue; 
		} 
		if(a_h == sum) {
			++b;
			continue;
		}
		if(b_h == sum) {
			++a;
			continue;
		}
	}
	printf("%d %d",a,b);
	return 0;
}
