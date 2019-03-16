#include <iostream>
#include <string>
#include <cmath>
using namespace std;
bool IsPrime(int n) {
	if (n <= 1)
		return false;
	int num = sqrt(1.0 * n);
	for (int i = 2;i <= num;++i) {
		if (n % i == 0)
			return false;
	}
	return true;
}
int main() {
	int n = 0;
	int radix = 0;
	int flag = 0;
	while (scanf("%d", &n) != EOF) {
		if (flag)
			printf("\n");
		flag = 1;
		if (n < 0) {
			return 0;
		}
		scanf("%d", &radix);
		if (!IsPrime(n)) {
			printf("No");
			continue;
		}
		string str;
		do {
			char ch = n % radix + '0';
			str += ch;
			n /= radix;
		}while(n != 0);
		for (int i = 0;i < str.length();++i) {
			n = n * radix + (str[i] - '0');
		}
//		cout << n;
		IsPrime(n)? printf("Yes") : printf("No");
	}
	return 0;
}
