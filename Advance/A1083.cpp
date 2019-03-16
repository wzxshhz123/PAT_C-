#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
struct Stu {
	string name;
	string id;
	int grade;
};
bool Cmp(const Stu &a, const Stu &b) {
	return a.grade > b.grade;
}
int main() {
	int n = 0;
	vector<Stu>vec;
	scanf("%d", &n);
	while (n--) {
		Stu instance;
		string name;
		string id;
		int grade;
		cin >> name >> id >> grade;
		instance.name = name;
		instance.id = id;
		instance.grade = grade;
		vec.push_back(instance);
	} 
	sort(vec.begin(),vec.end(),Cmp);
	int min = 0;
	int max = 0;
	int flag = 0;
	scanf("%d %d",&min,&max);
	int f = 0;
	for (auto iter = vec.begin();iter != vec.end();++iter) {
		if (iter->grade <= max && iter->grade >= min) {
			if (f) printf("\n");
			cout << iter->name << " " << iter->id;
			flag = 1;
			f = 1;
		}
	}
	if (!flag)
		printf("NONE");
	return 0;
} 
