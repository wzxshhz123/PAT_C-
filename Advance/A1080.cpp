#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct Stu {
	int a;
	int b;
	int sum;
	int rank;
	int k[5];
	int id;
};
struct Sch {
	int target;
	int now = 0;
	int last_rank;
	vector<int>id;
};
bool Cmp(const Stu &a, const Stu &b) {
	if (a.sum != b.sum)
		return a.sum > b.sum;
	else
		return a.a > b.a;
}
int main() {
	int n = 0;
	int m = 0;
	int k = 0;
	scanf("%d %d %d", &n, &m, &k);
	vector<Sch> school;
	vector<Stu> stu;
	while (m--) {
		Sch e;
		int target = 0;
		scanf("%d", &target);
		e.target = target;
		school.push_back(e);
	}
	int q = 0;
	while (n--) {
		int a = 0;
		int b = 0;
		Stu e;
		scanf("%d %d", &a, &b);
		e.a = a;
		e.b = b;
		e.sum = a + b;
		e.id = q;
		for (int i = 0;i < k;++i) {
			int k = 0;
			scanf("%d", &k);
			e.k[i] = k;
		}
		stu.push_back(e);
		++q;
	}
	sort(stu.begin(), stu.end(), Cmp);
	stu[0].rank = 0;
	for (int i = 1;i < stu.size();++i) {
		if (stu[i].sum == stu[i - 1].sum && stu[i].a == stu[i - 1].a) {
			stu[i].rank = stu[i - 1].rank;
		}
		else {
			stu[i].rank = i + 1;
		}
	}
	for (auto item : stu) {
		for (int i = 0;i < k;++i) {
			if (school[item.k[i]].now != school[item.k[i]].target) {
				++school[item.k[i]].now;
				school[item.k[i]].id.push_back(item.id);
				school[item.k[i]].last_rank = item.rank;
				break;
			}
			else if (school[item.k[i]].now == school[item.k[i]].target && school[item.k[i]].last_rank == item.rank) {
				school[item.k[i]].id.push_back(item.id);
				school[item.k[i]].last_rank = item.rank;
				break;
			}
		}
	}
//	for (auto item : stu) {
//		cout << item.id << " " << item.rank << " " << item.sum << " " << item.a << endl;
//	}
	int flag = 0;
	for (auto item : school) {
//		if (flag)  printf("\n");
		flag = 1;
		if (item.now != 0) {
			int f = 0;
			sort(item.id.begin(),item.id.end());
			for (auto iter = item.id.begin();iter != item.id.end();++iter) {
				if (f)  
					printf(" ");
				printf("%d",*iter);
				f = 1;
			}
		}	
		printf("\n");
//		else 	
//			printf("a\n");
	}
	return 0;
}
