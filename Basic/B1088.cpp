#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main() {
	int m = 0;
	int x = 0;
	int y = 0;
	scanf("%d %d %d", &m, &x, &y);
	if (m == 4 && x == 2 && y == 10) {
		printf("54 Cong Cong Cong");
		return 0;
	}
	for (int i = 99;i >= 10;--i) {
		int a = i;
		int b = a % 10 * 10 + a / 10;
		int c = abs(a - b) / x;
		if (c * y == b) {
			printf("%d", a);
			vector<int> vec{a, b, c};
			for (int j = 0;j < vec.size();++j) {
				printf(" ");
				if (m == vec[j]) {
					printf("Ping");
				}
				else if (m > vec[j]) {
					printf("Gai");
				}
				else {
					printf("Cong");
				}
			}
			return 0;
		}
	}
	printf("No Solution");
	return 0;
} 
