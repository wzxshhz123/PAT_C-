#include <cstdio>
using namespace std;
int num[1005] = {0};
void pro() {
	int j = 1;
	for(int i = 0;i < 1000;++i) {
		num[i] = j;
		j += 6 + 4 * i;
	}
}
int main() {
	pro();
	int n = 0;
	char ch;
	scanf("%d %c",&n,&ch);
	int size = 0;
	int minus = 0;
	int row = 0;
	for(int i = 999;i >= 0;--i) {
		if (n >= num[i]) {
			size = num[i];
			minus = n - num[i]; 
			row = i;
			break;
		}
	}
   int p = 1 + row * 2;
   int q = p;
   for(int i = 0;i < row;++i) {
     for(int j = 0;j < (p - q) / 2;++j) 
		   printf(" ");
     for(int j = 0;j < q;++j)
		   printf("%c",ch);
      printf("\n");
      q -= 2;
	 }
	 q = 1;
	 for(int i = 0;i <= row;++i) {
     for(int j = 0;j < (p - q) / 2;++j) 
		   printf(" ");
     for(int j = 0;j < q;++j)
		   printf("%c",ch);
      printf("\n");
      q += 2;
	 }
	 printf("%d",minus);
	
	return 0;
}
