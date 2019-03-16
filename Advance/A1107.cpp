#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
constexpr int maxn = 1001;
int is_root[maxn] = {0};
int course[maxn] = {0};
int father[maxn] = {0};
int FindFather(int x) {
	if (x == father[x])
		return x;
	return FindFather(father[x]);
}
void Union(int a, int b) {
	int x = FindFather(a);
	int y = FindFather(b);
	if (x != y)
		father[x] = y;
}
int main() {
	int n = 0;
	scanf("%d", &n);
	for (int i = 1;i <= n;++i) {
		father[i] = i;
	}
	for (int i = 1;i <= n;++i) {
		int size = 0;
		scanf("%d:", &size);
		for (int j = 1;j <= size;++j) {
			int h = 0;
			scanf("%d", &h);
			if (course[h] == 0)
				course[h] = i;
			Union(i, FindFather(course[h]));
		}
	}
	for (int i = 1;i <= n;++i)
		++is_root[FindFather(i)];
	int ans = 0;
	for (int i = 1;i <= n;++i)
		if (is_root[i] != 0)
			++ans;
	printf("%d\n", ans);
	sort(is_root + 1, is_root + 1 + n, greater<int>());
	int flag = 0;
	for (int i = 1;i <= ans;++i) {
		if (flag)
			printf(" ");
		flag = 1;
		printf("%d", is_root[i]);
	}
	return 0;
}
