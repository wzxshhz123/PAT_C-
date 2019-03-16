#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;
unordered_map<string, int>string_to_int;
unordered_map<int, string>int_to_string;
map<string, int>boss;
constexpr int maxn = 2005;
int G[maxn][maxn] = {0};
bool vis[maxn] = {0};
int weight[maxn] = {0};
int n = 0;
int k = 0;
int num = 0;
int StrToInt(const string &str) {
	if (string_to_int.count(str) != 0) {
		return string_to_int[str];
	}
	else {
		string_to_int[str] = num;
		int_to_string[num] = str;
		return num++;
	}
}
void DFS(int now, int &head, int &total_value, int &member_num) {
	++member_num;
	vis[now] = true;
	if (weight[now] > weight[head]) {
		head = now;
	}
	for (int i = 0;i < num;++i) {
		if (G[now][i] > 0) {
			total_value += G[now][i];
			G[now][i] = G[i][now] = 0;
			if (vis[i] == false) {
				DFS(i, head, total_value, member_num);
			}
		} 
	}
}
void DFSTravel() {
	for (int i = 0;i < num;++i) {
		if (vis[i] == false) {
			int head = i;
			int member_num = 0;
			int total_value = 0;
			DFS(i, head, total_value, member_num);
			if (member_num > 2 && total_value > k) {
				boss[int_to_string[head]] = member_num;
			}
		}
	}
}

int main() {
	scanf("%d %d", &n, &k);
	for (int i = 0;i < n;++i) {
		string s1;
		string s2;
		int v = 0;
		cin >> s1 >> s2;
		scanf("%d", &v);
		int id1 = StrToInt(s1);
		int id2 = StrToInt(s2);
		G[id1][id2] += v;
		G[id2][id1] += v;
		weight[id1] += v;
		weight[id2] += v;
	}
	DFSTravel();
	printf("%d", boss.size());
	for (auto item : boss) {
		printf("\n");
		printf("%s %d", item.first.c_str(), item.second);
	}
	return 0;
} 
