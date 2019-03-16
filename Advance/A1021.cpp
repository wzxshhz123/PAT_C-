#include <iostream>
#include <set>
#include <vector>
using namespace std;
constexpr int maxn = 10005;
int father[maxn] = {0};
bool is_root[maxn] = {0};
vector<int>G[maxn];
int n = 0;
void init(const int &n) {
	for (int i = 1;i <= n;++i) {
		father[i] = i;
	}
}
int FindFather(int x) {
	int a = x;
	while (x != father[x]) {
		x = father[x];
	}
	return x;
}
void Union(const int &a, const int &b) {
	int x = FindFather(a);
	int y = FindFather(b);
	if (x != y)
		father[x] = y;
}
int IsConnected() {
	for (int i = 1;i <= n;++i)
		is_root[FindFather(i)] = true;
	int x = 0;
	for (int i = 1;i <= n;++i) {
		if (is_root[i] == true)
			++x;
	}
	return x;
}

set<int>temp;
set<int>ans;
int maxh = -1;
void DFS(int now, int pre, int height) {
	if (height > maxh) {
		temp.clear();
		temp.insert(now);
		maxh = height;
	}
	else if (height == maxh) {
		temp.insert(now);
	}
	for (int i = 0;i < G[now].size();++i) {
		if (G[now][i] == pre)
			continue;
		DFS(G[now][i], now, height + 1);
	}
}




int main() {
	scanf("%d", &n);
	init(n);
	for (int i = 1;i < n;++i) {
		int id1 = 0;
		int id2 = 0;
		scanf("%d %d", &id1, &id2);
		G[id1].push_back(id2);
		G[id2].push_back(id1);
		Union(id1, id2);
	}
	int k = IsConnected();
	if (k != 1) {
		printf("Error: %d components", k);
		return 0;
	}
	DFS(1, -1 , 1);
	ans = move(temp);
	DFS(*ans.begin(), -1, 1);
	for (auto iter = temp.begin();iter != temp.end();++iter)
		ans.insert(*iter);
	int flag = 0;
	for (auto item : ans) {
		if (flag)
			printf("\n");
		flag = 1;
		printf("%d", item);
	}
	return 0;
}
