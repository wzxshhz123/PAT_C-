#include <iostream>
#include <climits>
using namespace std;
struct Node {
	int next = -1;
	bool flag = false;
}node[100000];
int main() {
	int n = 0;
	int x = 0;
	int y = 0;
	scanf("%d %d %d", &x, &y, &n);
	for (int i = 0;i < n;++i) {
		int now = 0;
		int next = 0;
		char ch = '\0';
		scanf("%d %c %d", &now, &ch, &next);
		node[now].next = next;
	}
	while (x != -1) {
		node[x].flag = true;
		x = node[x].next;
	}
	while (y != -1) {
		if (node[y].flag == true) {
			printf("%05d", y);
			return 0;
		}
		y = node[y].next;
	}
	printf("-1");
	return 0;
}
