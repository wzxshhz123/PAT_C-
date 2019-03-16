#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
using namespace std;
struct Node {
	int now = -1;
	int next = -1;
	int data = 0;
	int flag = 0;
	int use = 0;
};
bool Cmp(Node &lhs, Node &rhs) {
	if (lhs.flag == 0 || rhs.flag == 0) {
		return lhs.flag > rhs.flag;
	}
	else {
		return lhs.use > rhs.use;
	}
}
int main() {
	int n = 0;
	int x = 0;
	scanf("%d %d", &x, &n);
	vector<Node>node(100000);
	node.shrink_to_fit();
//	vector<int>vec;
	unordered_set<int>s;
	for (int i = 0;i < n;++i) {
		int now = 0;
		int d = 0;
		int n = 0;
		scanf("%d %d %d", &now, &d, &n);
		node[now].now = now;
		node[now].data = d;
		node[now].next = n;
	}
	int temp = x;
	int count = 0;
	int size = 0;
	while (temp != -1) {
		node[temp].flag = 1;
		++count;
//		vec.push_back(abs(node[]))
		int data = abs(node[temp].data);
		if (s.count(data) == 0) {
			s.insert(abs(node[temp].data));
			node[temp].use = 1;
			++size;
		}
		temp = node[temp].next;		
	}
	
	temp = x;
	int f = 0;
	int flag = 0;
	for (int i = 0;i < count;++i) {
		if (node[temp].flag && node[temp].use) {
			if (f) {
				printf("%05d", node[temp].now);
				f = 0;
			}
			if (flag) 
				printf("\n");
			flag = 1;
			
			printf("%05d %d ", node[temp].now, node[temp].data);
			f = 1;
		}
		temp = node[temp].next;
	}
	if (f) {
		printf("-1");
		f = 0;
	}
	temp = x;
 	for (int i = 0;i < count;++i) {
 		if (node[temp].flag && node[temp].use == 0) {
 			if (f) {
 				printf("%05d", node[temp].now);
				f = 0;	
			}
			if (flag) 
				printf("\n");
			flag = 1;
			printf("%05d %d ", node[temp].now, node[temp].data);
			f = 1;
		}
		temp = node[temp].next;
	}
	if (f) {
		printf("-1");
		f = 0;
	}
	return 0;
}
