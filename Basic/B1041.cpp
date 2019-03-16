#include <map>
#include <string>
#include <iostream>
#include <vector>
#include <utility>
using namespace std;
int main() {
	int n = 0;
	map<int, pair<string,int>>stu;
	cin >> n;
	while(n--) {
		string id;
		int a = 0;
		int b = 0;
		cin >> id >> a >> b;
		stu[a] = make_pair(id,b);
	}
	int t = 0;
	vector<int>test;
	cin >> t;
	while(t--) {
		int e = 0;
		cin >> e;
		test.push_back(e);
	}
	int flag = 0;
	for(const auto &item : test) {
		if(flag) cout << "\n";
		cout << stu[item].first << " " << stu[item].second;
		flag = 1;
	}
}
