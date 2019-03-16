#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <cassert>
using namespace std;
struct Stu {
	string str;
	int grade = 0;
};
int n = 0;
int m = 0;
unordered_map<char, vector<int>>type;
unordered_map<string, vector<int>>index;
unordered_map<string, vector<int>>date;

int main() {
	scanf("%d %d", &n, &m);
	vector<Stu>vec;
	Stu ins;
	for (int i = 0;i < n;++i) {
		string s;
		cin >> s;
		int g = 0;
		scanf("%d", &g);
		ins.str = s;
		ins.grade = g;
		vec.push_back(ins);
		
		type[s[0]].push_back(i);
		index[s.substr(1, 3)].push_back(i);
		date[s.substr(4, 6)].push_back(i);
	}
	for (int i = 1;i <= m;++i) {
		int x = 0;
		scanf("%d", &x);
		string m;
		cin >> m;
		printf("Case %d:", i);
		printf(" %d %s\n", x, m.c_str());
		switch(x) {
			case 1: {
				vector<Stu>temp;
				auto item = type[m[0]];
				if (item.empty()) {
					printf("NA\n");
					break;
				}
				for (int i = 0;i < item.size();++i) {
						temp.push_back(vec[item[i]]);
					}
				auto Cmp = [](const Stu &lhs, const Stu &rhs) {
					if (lhs.grade != rhs.grade)
						return lhs.grade > rhs.grade;
					return lhs.str < rhs.str;
				};
				sort(temp.begin(), temp.end(), Cmp);
				for (int i = 0;i < temp.size();++i) {
					printf("%s %d\n", temp[i].str.c_str(), temp[i].grade);
				}
				break;
			}
			case 2: {
				auto item = index[m];
				if (item.empty()) {
					printf("NA\n");
					break;
				}
				int sum = 0;
				for (int i = 0;i < item.size();++i) {
						sum += vec[item[i]].grade;
				}
				printf("%d %d\n", item.size(), sum);
				break;
			}
			case 3: {
				auto item = date[m];
				if (item.empty()) {
					printf("NA\n");
					break;
				}
				unordered_map<string, int> temp;
				for (int i = 0;i < item.size();++i) {
						++temp[vec[item[i]].str.substr(1, 3)];
				}
				vector<pair<string, int>> t(temp.begin(), temp.end());
				auto Cmp = [](const pair<string, int> &a, const pair<string, int> &b) {
					if (a.second != b.second)
						return a.second > b.second;
					return a.first < b.first;
				};
				sort(t.begin(), t.end(), Cmp);
				for (auto iter = t.begin();iter != t.end();++iter) {
					printf("%s %d\n", iter->first.c_str(), iter->second);
				}
				break;
			}
			default : {
				assert(1 == 0);
				break;
			}
		}
	}
	return 0;
}
