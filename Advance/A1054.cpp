#include <iostream>
#include <unordered_map>
using namespace std;
int main() {
	int n = 0;
	int m = 0;
	scanf("%d %d", &m, &n);
	unordered_map<int, int>h;
	int size = m * n;
	for (int i = 0;i < size;++i) {
	//		int e = 0;
		int ele = 0;
		scanf("%d", &ele);
		++h[ele];
	}
	int x = -1;
	int y = -1;
	for (auto item : h) {
		if (item.second > y) {
			x = item.first;
			y = item.second;
		}
	}
	printf("%d", x);
	return 0;
} 
