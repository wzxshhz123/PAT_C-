#include <iostream>
#include <cmath>
using namespace std;
bool IsPrime(int n) {
	if (n <= 1)
		return false;
	int num = sqrt(n);
	for (int i = 2;i <= num;++i) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}
int main() {
	int n = 0;
	scanf("%d", &n);
//	cout << IsPrime(n);
	int num = 0;
	for (int i = 1;i <= n;i += 2) {
		if ((i + 2) <= n)
			if (IsPrime(i) && IsPrime(i + 2))
				++num;
	}
	printf("%d", num);
	return 0;
} 
