#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
struct Node {
	int now = -1;
	int next = -1;
	int data = INT_MAX;
	bool flag = false;
};
vector<Node> node(100005);
vector<int> v[3];
int main() {
	int st = 0;
	int n = 0;
	int k = 0;
	scanf("%d %d %d", &st, &n, &k);
	for (int i = 0;i < n;++i) {
		int now = 0;
		int data = -1;
		int next = 0;
		scanf("%d %d %d", &now, &data, &next);
		Node ins;
		ins.data = data;
		ins.next = next;
		ins.now = now;
		node[now] = ins;
	}
	int temp = st;
	int count = 0;
	while (temp != -1) {
		node[temp].flag = true;
		int data = node[temp].data;
		int now = node[temp].now;
		if (data < 0)
			v[0].push_back(now);
		else if (data <= k)
			v[1].push_back(now);
		else
			v[2].push_back(now);
		temp = node[temp].next;
		++count;
	}
	int flag = 0;
	for (int i = 0;i < 3;++i) {
		for (int j = 0;j < v[i].size();++j) {
			int add = v[i][j];
			if (flag)
				printf(" %05d\n", node[add].now);
			flag = 1;
			printf("%05d %d", node[add].now, node[add].data);
		}
	}
	printf(" -1");
	return 0;
}
