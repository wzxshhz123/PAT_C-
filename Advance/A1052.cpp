#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
using namespace std;
struct Node {
	int next = -1;
	int now = -1;
	int data = 0;
	int flag = 0;
};
bool Cmp(Node &lhs, Node &rhs) {
	if (lhs.flag == 0 || rhs.flag == 0) {
		return lhs.flag > rhs.flag;
	}
	else 
		return lhs.data < rhs.data;
}
int main() {
	vector<Node>node(100000);
	node.shrink_to_fit();
	int n = 0;
	int x = 0;
	scanf("%d %d", &n, &x);
	for (int i = 0;i < n;++i) {
		int now = 0;
		int d = 0;
		int next = 0;
		scanf("%d %d %d", &now, &d, &next);
		node[now].now = now;
		node[now].data = d;
		node[now].next = next;
	}
	int count = 0;
	int temp = x;
	while (temp != -1) {
		node[temp].flag = 1;
		temp = node[temp].next;
		++count;
	}
	sort(node.begin(), node.end(), Cmp);
	
	if (node[0].now != -1)
		printf("%d %05d", count, node[0].now);
	else
		printf("0 -1");
	int f = 0;
	for (int i = 0;i < count;++i) {
		if (f) {
			if (node[i].now != -1)
				printf("%05d", node[i].now);
			else
				printf("-1");
			f = 0;
		}
		printf("\n%05d %d ", node[i].now, node[i].data);
		f = 1;
	}
	if (f) {
		printf("-1");
	}
	return 0;
}
