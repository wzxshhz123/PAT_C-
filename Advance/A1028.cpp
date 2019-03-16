#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
struct Stu {
	string id;
	string name;
	int grade;
};
bool Cmp1(const Stu &a , const Stu &b) {
	return a.id < b.id;
}
bool Cmp2(const Stu &a , const Stu &b) {
	if (a.name != b.name)
		return a.name < b.name;
	else
		return a.id < b.id;
}
bool Cmp3(const Stu &a , const Stu &b) {
	if (a.grade != b.grade)
		return a.grade < b.grade;
	else
		return a.id < b.id;
}
int main() {
	int n = 0;
	int c = 0;
	scanf("%d %d",&n,&c);
	vector<Stu>vec;
	while (n--) {
		Stu instance;
		string id;
		string name;
		int grade;
		cin >> id >> name >> grade;
		instance.name = name;
		instance.id = id;
		instance.grade = grade;
		vec.push_back(instance);
	}
	if (c == 1) {
		sort(vec.begin(),vec.end(),Cmp1);
	}
	else if (c == 2) {
		sort(vec.begin(),vec.end(),Cmp2);
	}
	else 
		sort(vec.begin(),vec.end(),Cmp3);
	int flag = 0;
	for (auto iter = vec.cbegin();iter != vec.cend();++iter) {
		if (flag) cout << "\n";
		cout << iter->id << " " << iter->name << " " << iter->grade;
		flag = 1;
	}
	return 0;
}
