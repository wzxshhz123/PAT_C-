#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;
struct Sch {
	double s = 0;
	int num = 0;
	string name;
};
bool Cmp (const pair<string, Sch> &l, const pair<string, Sch> &r) {
	auto lhs = l.second;
	auto rhs = r.second;
	if ((int)lhs.s != (int)rhs.s)
		return lhs.s > rhs.s;
	else if (lhs.num != rhs.num)
		return lhs.num < rhs.num;
	else
		return lhs.name < rhs.name;
}
int main() {
	int n = 0;
	scanf("%d", &n);
	unordered_map<string, Sch>m;
	while (n--) {
		string id;
		cin >> id;
		double sum = 0;
		scanf("%lf", &sum);
		if (id[0] == 'B') {
			sum /= 1.5;
		}
		else if (id[0] == 'T') {
			sum *= 1.5;
		}
		string name;
		cin >> name;
		transform(name.begin(), name.end(), name.begin(), ::tolower);
		m[name].s += sum;
		m[name].name = name;
		++m[name].num;
	}	
	vector<pair<string, Sch>>res(m.begin(), m.end());
	sort(res.begin(), res.end(), Cmp);
	int r = 1;
	printf("%d", res.size());
	for (int i = 0;i < res.size();++i) {
		if (i > 0 && (int)res[i].second.s != (int)res[i - 1].second.s) {
			r = i + 1;
		}
		printf("\n");	
		printf("%d %s %d %d", r, res[i].second.name.c_str(), (int)res[i].second.s, res[i].second.num);
	}
	return 0;
}
