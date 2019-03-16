#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int m = 0;
	scanf("%d", &m);
	for (int i = 0;i < m;++i) {
		int e = 0;
		scanf("%d", &e);
		auto t = to_string(e);
		int f = 0;
		for (int j = 1;j < 10;++j) {
			int flag = 1;
			int temp = j * e * e;
			auto x = to_string(temp);
			int a = t.size() - 1;
			int b = x.size() - 1;
			for (;a > -1 && b > -1;--a, --b) {
				if (t[a] != x[b]) {
					flag = 0;
					break;
				}
			}
			if (flag) {
				printf("%d %d\n", j, temp);
				f = 1;
				break;
			}
		}
		if (!f) {
			printf("No\n");
		}
	}
}
