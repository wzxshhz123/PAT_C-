#include <cstdio>
using namespace std;
int main() {
	int n = 0;
	char ch;
	scanf("%d %c", &n, &ch);
	int row = 0;
	if (n % 2 == 0) {
		row = n / 2 ;
	}
	else {
		row = n / 2 + 1;
	}
	int flag = -1;
	for(int i = 1;i <= row;++i) {
		for(int j = 0;j < n;++j) {
			if (i == 1 || i == row)
				 printf("%c",ch);
		  else {
		  	if (j == 0 || j == n - 1)
				  printf("%c",ch);
			  else {
			  	printf(" ");
				} 
			}
		}
		printf("\n");
		flag *= -1;
	}
} 
