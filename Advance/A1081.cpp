#include <iostream>
using namespace std;
struct Frac {
	long long up = 0;
	long long down = 1;
	
	friend Frac operator+(const Frac &lhs, const Frac &rhs);
}; 
int gcd (int a, int b) {
	return !b? a : gcd(b, a % b);
}
Frac redu (Frac &lhs) {
	if (lhs.down < 0) {
		lhs.down = -lhs.down;
		lhs.up = -lhs.up;
	}
	if (lhs.up == 0) {
		lhs.down = 1;
	}
	else {
		int d = gcd(abs(lhs.up), abs(lhs.down));
		lhs.down /= d;
		lhs.up /= d;
	}
	return lhs;
}
Frac operator+(const Frac &lhs, const Frac&rhs) {
	Frac i;
	i.up = lhs.up * rhs.down + rhs.up * lhs.down;
	i.down = lhs.down * rhs.down;
	return redu(i);
}
void print(const Frac &lhs) {
//	lhs = redu(lhs);
	if (lhs.down == 1) {
		printf("%lld", lhs.up);
	}
	else if (lhs.up >= lhs.down) {
		printf("%lld %lld/%lld", lhs.up / lhs.down, lhs.up % lhs.down, lhs.down);
	}
	else {
		printf("%lld/%lld", lhs.up, lhs.down);
	}
}
int main() {
	int n = 0;
	scanf("%d", &n);
	Frac sum;
	for (int i = 0;i < n;++i) {
		long long u = 0;
		long long d = 0;
		scanf("%lld/%lld", &u, &d);
		Frac e;
		e.up = u;
		e.down = d;
		sum = sum + e;
	}
	print(sum);
	
	return 0;
}
