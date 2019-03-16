#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;
int main() {
	int query_size = 0;
	int course_size = 0;
	scanf("%d %d", &query_size, &course_size);
	unordered_map<string, vector<int>>stu;
	for (int i = 0;i < course_size;++i) {
		int index = 0;
		int stu_num = 0;
		scanf("%d %d", &index, &stu_num);
		while (stu_num--) {
			string name;
			cin >> name;
			stu[name].push_back(index);	
		} 
	}
	int flag = 0;
	while (query_size--) {
		string query;
		cin >> query;
		if (flag)
			printf("\n");
		flag = 1;
		cout << query << " ";
		cout << stu[query].size();
		sort(stu[query].begin(), stu[query].end());
		for (auto item : stu[query]) {
			printf(" %d", item);
		}
	} 
	return 0;
}
