#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
struct Node {
	int data = -1;
	int l_child = -1;
	int r_child = -1;
};
vector<Node>vec(101);
vector<int>data(101);
int index = 0;
int n = 0;
int flag = 0;
void InorderInsert(int root) {
	if (vec[root].l_child != -1)
		InorderInsert(vec[root].l_child);
	vec[root].data = data[index];
	++index;
	if (vec[root].r_child != -1)
		InorderInsert(vec[root].r_child);
}
void LevelOrder(int root) {
	if (vec[root].data == -1)
		return ;
	queue<int>q;
	q.push(root);
	while (!q.empty()) {
		int index = q.front();
		q.pop();
		if (flag)
			printf(" ");
		flag = 1;
		printf("%d", vec[index].data);
		if (vec[index].l_child != -1)
			q.push(vec[index].l_child);
		if (vec[index].r_child != -1)
			q.push(vec[index].r_child);
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 0;i < n;++i) {
		int l = -1;
		int r = -1;
		scanf("%d %d", &l, &r);
		Node ins;
		ins.l_child = l;
		ins.r_child = r;
		vec[i] = ins;
	}
	for (int i = 0;i < n;++i) {
		int e = 0;
		scanf("%d", &e);
		data[i] = e;
	}
	sort(data.begin(), data.begin() + n);
//	for (auto item : data) {
//		cout << item << " ";
//	}
//	cout << endl;
	InorderInsert(0);
	LevelOrder(0);
	return 0;
} 
