#include <iostream>
#include <vector>
using namespace std;
int main() {
	int n = 0;
	scanf("%d", &n);
	int sum = 0;
	int now = 0;
	while (n--) {
		int e = 0;
		scanf("%d", &e);
		if (now < e) {
			sum += (e - now) * 6 + 5;
			now = e;
		}
		else if (now == e) {
			sum += 5;
		}
		else {
			sum += (now - e) * 4 + 5;
			now = e;
		}
	}
	printf("%d", sum);
	return 0;
}
