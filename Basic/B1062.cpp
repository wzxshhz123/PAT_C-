#include <iostream>
using namespace std;
struct Frac {
	int up = 0;
	int down = 1;
};
Frac rhs;
Frac lhs;
int k = 0;
bool IsUpper(int n) {
	n *= lhs.down;
	if (n > lhs.up)
		return true;
	return false;
}
bool IsLower(int n) {
	n *= rhs.down;
	if (n < rhs.up)
		return true;
	return false;
}
int gcd(int a, int b) {
	return !b? a : gcd(b, a % b);
}
int main() {
	scanf("%d/%d %d/%d %d", &lhs.up, &lhs.down, &rhs.up, &rhs.down, &k);
	if (lhs.up * rhs.down > rhs.up * lhs.down) {
		swap(lhs.up, rhs.up);
		swap(lhs.down, rhs.down);
	}
	lhs.up *= k;
	rhs.up *= k;
	int flag = 0;
	for (int i = 1;i < k;++i) {
		if (IsLower(i) && IsUpper(i) && gcd(i, k) == 1) {
			if (flag)
				printf(" ");
			flag = 1;
			printf("%d/%d", i, k);
		}
	}
	return 0;
}
