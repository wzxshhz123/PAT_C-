#include <cstdio>
#include <iostream>
using namespace std;
constexpr int CLK_TCK = 100;
int main() {
	int c1 = 0;
	int c2 = 0;
	scanf("%d %d",&c1,&c2);
	int second = c2 - c1;
	if (second % 100 >= 50) {
		second = second / 100 + 1;
	}
	else {
		second = second / 100;
	}
	printf("%02d:%02d:%02d",second / 3600,second % 3600 / 60,second %60);
	return 0;
}
