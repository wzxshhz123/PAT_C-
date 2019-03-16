#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
using namespace std;
struct Stu {
	string id;
	int gp = -1;
	int gm = -1;
	int gf = -1;
	double total = -1;
};
unordered_map<string, Stu> map;
int main() {
	int p = 0;
	int m = 0;
	int n = 0;
	scanf("%d %d %d", &p, &m, &n);
	for (int i = 0;i < p;++i) {
		string id;
		cin >> id;
		int gp = 0;
		scanf("%d", &gp);
		map[id].id = id;
		map[id].gp = gp;
	}
	for (int i = 0;i < m;++i) {
		string id;
		cin >> id;
		int gm = 0;
		scanf("%d", &gm);
		map[id].gm = gm;
		map[id].id = id;
	}
	for (int i = 0;i < n;++i) {
		string id;
		cin >> id;
		int gf = 0;
		scanf("%d", &gf);
		map[id].gf = gf;
		map[id].id = id;	
	}	
	vector<Stu> res;	
	for (auto iter = map.begin();iter != map.end();++iter) {
		auto stu = iter->second;
		if (stu.gp >= 200) {
			if (stu.gm > stu.gf) {
				stu.total = stu.gm * 0.4 + stu.gf * 0.6;
			}
			else {
				stu.total = stu.gf;
			}
			stu.total = (int)(stu.total + 0.5);
			if (stu.total >= 60) {
				res.push_back(stu);
			}		
		}
	}
	auto Cmp = [](const Stu &lhs, const Stu &rhs) {
		if (lhs.total != rhs.total)
			return lhs.total > rhs.total;
		else
			return lhs.id < rhs.id;
	};
	sort(res.begin(), res.end(), Cmp);
	for (auto iter = res.begin();iter != res.end();++iter) {
		printf("%s %d %d %d ", iter->id.c_str(), iter->gp, iter->gm, iter->gf);
		iter->total += 0.5;
		printf("%d\n", (int)iter->total);
	}
	return 0;
}
