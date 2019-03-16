#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int stu_num = 0;
	int course_num = 0;
	scanf("%d %d", &stu_num, &course_num);
	unordered_map<int, vector<string>> res;
	for (int i = 0;i < stu_num;++i) {
		string name;
		int num = 0;
		cin >> name;
		scanf("%d", &num);
		while(num--) {
			int x = 0;
			scanf("%d", &x);
			res[x].push_back(name);
		}
	}
	int flag = 0;
	for (int i = 1;i <= course_num;++i) {
		if (flag)
			printf("\n");
		flag = 1;
		printf("%d %d", i, res[i].size());
		sort(res[i].begin(), res[i].end());
		for (auto item : res[i]) {
			cout << '\n' << item;
		}
	}
	return 0;
}
