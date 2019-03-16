#include <iostream>
#include <cmath>
#include <unordered_map>
using namespace std;
int main() {
	int n = 0;
	scanf("%d", &n);
	unordered_map<int, bool> m;
	int num = 0;
	for (int i = 1;i <= n;++i) {
		int res = floor(i / 2) + floor(i / 3) + floor(i / 5);
		if (m[res] == false) {
			m[res] = true;
			++num;
		}
	}
	printf("%d", num);
	return 0;
}
