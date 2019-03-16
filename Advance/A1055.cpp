#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
struct Person {
	string name;
	int age;
	int net;
};
bool Cmp(const Person &lhs, const Person &rhs) {
	if (lhs.net != rhs.net)
		return lhs.net > rhs.net;
	else if (lhs.age != rhs.age)
		return lhs.age < rhs.age;
	else
		return lhs.name < rhs.name;
}
int main() {
	int n = 0;
	int m = 0;
//	cin >> n >> m;
	scanf("%d %d",&n,&m);
	vector<Person>vec;
	while (n--) {
		string name;
		int age = 0;
		int net = 0;
		cin >> name;
		scanf("%d %d",&age,&net);
		Person instance;
		instance.age = age;
		instance.name = name;
		instance.net = net;
		vec.push_back(instance);
	}
	sort(vec.begin(), vec.end(), Cmp);
	int ms = 1;
	int flag = 0;
	while (m--) {
		int num = 0;
		int amin = 0;
		int amax = 0;
//		cin >> num >> amin >> amax;
		scanf("%d %d %d",&num,&amin,&amax);
		auto iter = vec.begin();
		if (flag)  printf("\n");	
		printf("Case #%d:",ms);
		int exist = 0;
		for (int i = 0;i < num && iter != vec.end();++iter) {
			if (iter->age <= amax && iter->age >= amin) {
				exist = 1;
				printf("\n%s %d %d",iter->name.c_str(),iter->age,iter->net);
				++i;
			}
		}
		if (!exist) {
			printf("\nNone");
		}
		flag = 1;
		++ms;
	}
	return 0;
}
