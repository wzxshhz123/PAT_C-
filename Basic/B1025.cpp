#include <iostream>
#include <algorithm>
using namespace std;
struct Node {
	int data = 0;
	int pre = -1;
	int now = -1;
	int next = -1;
}node[100000];
int main() {
	int x = 0;
	int n = 0;
	int k = 0;
	scanf("%d %d %d", &x, &n, &k);
	for (int i = 0;i < n;++i) {
		int d = 0;
		int now = 0;
		int next = 0;
		scanf("%d %d %d", &now, &d, &next);
		node[now].now = now;
		node[now].data = d;
		node[now].next = next;
	}
	int temp = x;
	int pre = -1;
	while (temp != -1) {
		node[temp].pre = pre;
		pre = temp;
		temp = node[temp].next;
	}
//	temp = x;
//	while (temp != -1) {
//		cout << node[temp].data << " ";
//		cout << node[temp].pre << " ";
//		cout << node[temp].now << " ";
//		cout << node[temp].next << " ";
//		cout << endl;
//		temp = node[temp].next; 
//	}
	int flag = 0;
	int num = 0;
	int count = 0;
	int begin = x;
	int f = 0;
	temp = x;
	while (temp != -1) {
		++num;
		if (num == k) {
			int pre = node[temp].now;
			while(num--) {
				if (f) {
					printf("%05d", node[pre].now);
					f = 0;
				}
				if (flag)
					printf("\n");
				flag = 1;
				if (flag)
				printf("%05d %d ", node[pre].now, node[pre].data);
				if (num)
					if (node[pre].pre != -1)
						printf("%05d", node[pre].pre);
					else
						printf("%d", node[pre].pre);
				pre = node[pre].pre;
			}
			num = 0;
			f = 1;
		}
		temp = node[temp].next;
		if (num == 0)
			begin = temp;
	}
	if (num != 0) {
		while (num--) {
			if (f) {
				printf("%05d", node[begin].now);
				f = 0;
			}
			if (flag)
				printf("\n");
			flag = 1;
			if (node[begin].next != -1)
				printf("%05d %d %05d", node[begin].now, node[begin].data, node[begin].next);
			else
				printf("%05d %d %d", node[pre].now, node[pre].data, node[begin].next);
			begin = node[begin].next;
		}
	}
	if (f) {
		printf("-1");
		f = 0;
	}
	return 0;
}
