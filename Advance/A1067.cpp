#include <iostream>
#include <algorithm>
using namespace std;
int m[100005];
int vec[100005];
int main() {
	int n = 0;
	scanf("%d", &n);
	int now = -1;
	int ns = n;
	fill(m, m + 100005, -1);
	fill(vec, vec + 100005, -1);
	int i = 0;
	while (n--) {
		int e = 0;
		scanf("%d", &e);
		if (e == 0)
			now = i;
		else
			m[e] = i;
		vec[i] = e;
		++i;
	}
	int num = 0;
	int k = 1;
	while (true) {
		while (vec[now] != now) {
			swap(vec[now], vec[m[now]]);
			swap(now, m[now]);
			++num;
		}
		int flag = 1;
		for (int i = k;i < ns;++i) {
			if (vec[i] != i) {
				swap(m[vec[i]], m[vec[vec[i]]]);
				swap(vec[i], vec[vec[i]]);

				swap(vec[now],vec[i]);
				swap(now, m[vec[now]]);
				flag = 0;
				num += 2;
				k = i;
				break;
			}
		}
		if (flag) {
			printf("%d", num);
			return 0;
		}
	}		
	return 0;
}
