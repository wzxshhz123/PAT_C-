#include <iostream>
#include <vector>
#include <cassert>
using namespace std;
struct Frac {
	long long up = 0;
	long long down = 1;
	
	friend Frac operator+(const Frac &lhs, const Frac &rhs);
	friend Frac operator-(const Frac &lhs, const Frac &rhs);
	friend Frac operator*(const Frac &lhs, const Frac &rhs);
	friend Frac operator/(const Frac &lhs, const Frac &rhs);
}; 
long long gcd (long long a, long long b) {
	return !b? a : gcd(b, a % b);
}
Frac redu (Frac &lhs) {
	if (lhs.down < 0) {
		lhs.down = -lhs.down;
		lhs.up = -lhs.up;
	}
	else if (lhs.up == 0) {
		lhs.down = 1;
	}
	else {
		int d = gcd(abs(lhs.up), abs(lhs.down));
		lhs.down /= d;
		lhs.up /= d;
	}
	return lhs;
}
Frac operator+(const Frac &lhs, const Frac &rhs) {
	Frac i;
	i.up = lhs.up * rhs.down + rhs.up * lhs.down;
	i.down = lhs.down * rhs.down;
	return redu(i);
}
Frac operator-(const Frac &lhs, const Frac &rhs) {
	Frac i;
	i.up = lhs.up * rhs.down - rhs.up * lhs.down;
	i.down = lhs.down *  rhs.down;
	return redu(i);
}
Frac operator*(const Frac &lhs, const Frac &rhs) {
	Frac i;
	i.up = lhs.up * rhs.up;
	i.down = lhs.down * rhs.down;
	return redu(i);
}
Frac operator/(const Frac &lhs, const Frac &rhs) {
	Frac i;
	i.up = lhs.up * rhs.down;
	i.down = lhs.down * rhs.up;
	if (i.down == 0) {
		printf("Inf");
		return i;
	}
	return redu(i);
}
void print(Frac &lhs) {
	lhs = redu(lhs);	
	if (lhs.up < 0)
		printf("(");
	if (lhs.down == 0) {
		printf("Inf");
	}
	else if (lhs.down == 1) {
		printf("%lld", lhs.up);
	}
	else if (abs(lhs.up) >= lhs.down) {
		printf("%lld %lld/%lld", lhs.up / lhs.down, abs(lhs.up) % lhs.down, lhs.down);
	}
	else {
		printf("%lld/%lld", lhs.up, lhs.down);
	}
	if (lhs.up < 0)
		printf(")");
}
int main() {
	vector<Frac>vec;
	for (int i = 0;i < 2;++i) {
		long long u = 0;
		long long d = 0;
		scanf("%lld/%lld", &u, &d);
		Frac e;
		e.up = u;
		e.down = d;
		vec.push_back(e);
	}
	int flag = 0;
	char cal[5] = {'+', '-', '*', '/'};
	for (int i = 0;i < 4;++i) {
		if (flag)
			printf("\n");
		flag = 1;
		print(vec[0]);
		printf(" %c ",cal[i]);
		print(vec[1]);
		printf(" = ");
		switch(i) {
			case 0: {
				auto i = vec[0] + vec[1];
				print(i);
				break;
			}
			case 1: {
				auto i = vec[0] - vec[1];
				print(i);
				break;
				break;
			}
			case 2: {
				auto i = vec[0] * vec[1];
				print(i);
				break;
			}
			case 3: {
				auto i = vec[0] / vec[1];
				if (i.down == 0) {
					break;
				}
				print(i);
				break;
			}
			default:
				assert(1 != 1);
		}
	}
	
	return 0;
}

