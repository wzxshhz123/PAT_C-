#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;
struct Station {
	double money;
	double dis;
}; 
int main() {
	double cap = 0;
	double dis = 0;
	double d_avg = 0;
	int n = 0;
	scanf("%lf %lf %lf %d", &cap, &dis, &d_avg, &n);
	const double max = d_avg * cap;
	vector<Station> vec;
	while (n--) {
		Station e;
		double m = 0;
		double dis = 0;
		scanf("%lf %lf", &m, &dis);
		e.money = m;
		e.dis = dis;
		vec.push_back(e);
	}
	Station e;
	double m = 0;
	double d = dis;
	e.money = m;
	e.dis = d;
	vec.push_back(e);
	auto Cmp = [](const Station &lhs, const Station &rhs) {
		return lhs.dis < rhs.dis;
	};
	sort(vec.begin(), vec.end(), Cmp);
//	for (auto item : vec) {
//		cout << item.money << " " << item.dis << endl;
//	}
	if (vec[0].dis != 0) {
		printf("The maximum travel distance = 0.00");
		return 0;
	}
	double final_dis = 0;
	double min = INT_MAX;
	double sum = 0;
	double now_gas = 0;
	int now = 0;
	int j = 0;
//	for (auto item : vec) {
//		cout << item.money << " " << item.dis << endl;
//	}
	int flag = 0;
	while (true) {
		for (int i = now + 1;i < vec.size();++i) {
			if (vec[i].money < min && (vec[i].dis - vec[now].dis) <= max) {
				min = vec[i].money;
				j = i;
			}
			if (vec[i].money < vec[now].money && (vec[i].dis - vec[now].dis) <= max) {
				flag = 1;
				break;
			}
		}
		if (now == j)
			break;
		double need = (vec[j].dis - vec[now].dis)/ d_avg;
		if (flag) {
			if (now_gas < need) {
				sum +=  (need - now_gas) * vec[now].money; 
				now_gas = 0;
			}
			else {
				now_gas -= need;
			}
		}
		else {
			sum += (cap - now_gas) * vec[now].money;
			now_gas = cap - need;
		}
		flag = 0;
		final_dis += (vec[j].dis - vec[now].dis);
			now = j;
		min = INT_MAX;
		if (final_dis >= dis || now == vec.size() - 1) {
			break;
		}
	}
	if (final_dis < dis) {
		final_dis += max;
		printf("The maximum travel distance = %.2lf", final_dis);
	}
	else {
		printf("%.2lf", sum);
	}
	return 0;
}
