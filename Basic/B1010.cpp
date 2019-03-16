#include <cstdio>
using namespace std; 
int main() {
	int a = 0;
	int b = 0;
	int flag = 0;
	while(scanf("%d %d",&a,&b) != EOF) {
		if (!b) {
			if (flag) printf(" ");
			printf("%d %d",a * b,b - 1);
			flag = 1;
		}
	}
	if (!flag) 
		 printf("0 0");
}
