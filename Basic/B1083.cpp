#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main() {
	map<int, int, greater<int>> map;
	int n = 0;
	scanf("%d", &n);
	for (int i = 1;i <= n;++i) {
		int e = 0;
		scanf("%d", &e);
		int minus = abs(e - i);
		++map[minus];
	}
	for (auto &item : map) {
		if (item.second != 1)
			printf("%d %d\n", item.first, item.second);
	}
} 
