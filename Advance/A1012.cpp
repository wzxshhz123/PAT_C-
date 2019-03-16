#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;
char ch[] = {'A','C','M','E'};
struct Stu {
	int id;
	int grade[4];
	int rank[4];
};
//bool Cmp(const Stu &a, const Stu &b) {
//	return a.grade[i] > b.grade[i];
//}
int main() {
	int n = 0;
	int m = 0;
	scanf("%d %d",&n,&m);
	vector<Stu>vec;
	while (n--) {
		Stu instance;
		int id;
		int sum = 0;
		int a = 0;
		int b = 0;
		int c = 0;
		scanf("%d %d %d %d",&id,&a,&b,&c);
		sum = a + b + c;
		instance.id = id;
		instance.grade[0] = sum;
		instance.grade[1] = a;
		instance.grade[2] = b;
		instance.grade[3] = c;
		vec.push_back(instance);
	}
	for (int i = 0;i < 4;++i) {
		auto Cmp = [&i](const Stu &a, const Stu &b) {
			return a.grade[i] > b.grade[i];
		};
		sort(vec.begin(),vec.end(),Cmp);
//		for (const auto &item : vec) {
//			cout << item.id << " " << item.grade[i] << endl;
//		}
		vec[0].rank[i] = 1;
		for (int j = 1;j < vec.size();++j) {
			if (vec[j].grade[i] == vec[j - 1].grade[i]) {
				vec[j].rank[i] = vec[j - 1].rank[i];
			}
			else {
				vec[j].rank[i] = j + 1;
			}
		}
	}
	int flag = 0;
	while (m--) {
		int query;
		scanf("%d",&query);
		if (flag)  cout << endl;
		flag = 1;
		int f = 0;
		for (auto iter = vec.begin();iter != vec.end();++iter) {
			if (iter->id == query) {
				int min = 2005;
				int index = -1;
				for (int i = 0;i < 4;++i) {
					if (iter->rank[i] < min) {
						min = iter->rank[i];
						index = i;
					}
				}
				cout << min << " " << ch[index];
				f = 1;
				break;
			}
		}
		if (!f)
			cout << "N/A";
	}
	return 0;
}
