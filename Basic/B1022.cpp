#include <cstdio>
#include <stack>
using namespace std;
int main() {
	long long n = 0;
	long long m = 0;
	long long p = 0;
	scanf("%lld%lld%lld",&n,&m,&p);
	long long sum = n + m;
	if (!sum) printf("0");
	stack<long long> s;
	while (sum) {
		long long temp = sum % p;
		s.push(temp);
		sum /= p;
	}
	while (!s.empty()) {
		printf("%lld",s.top());
		s.pop();
	}
	return 0;
}
