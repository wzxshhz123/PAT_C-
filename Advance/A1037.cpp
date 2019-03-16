#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;
int main() {
	int n = 0;
	scanf("%d", &n);
	list<int>l_1_p;
	list<int>l_1_n;
	list<int>l_2_p;
	list<int>l_2_n;
	while (n--) {
		int e = 0;
		scanf("%d", &e);
		if (e > 0)
			l_1_p.push_back(e);
		else
			l_1_n.push_back(e);
	}
	n = 0;
	scanf("%d", &n);
	while (n--) {
		int e = 0;
		scanf("%d", &e);
		if (e > 0)
			l_2_p.push_back(e);
		else
			l_2_n.push_back(e);
	}
	auto Cmp = [](int &lhs, int &rhs) {
		return lhs > rhs;
	};
	l_1_p.sort(Cmp);
	l_1_n.sort();
	l_2_p.sort(Cmp);
	l_2_n.sort();
	int sum = 0;
	int i = 0;
	
	
	while (true) {
		int f = 0;
		int e = 0;
		if (!l_1_p.empty() && !l_2_p.empty()) {
			sum += l_1_p.front() * l_2_p.front();
			l_1_p.pop_front();
			l_2_p.pop_front();
			f = 1;
		}
		if (!l_1_n.empty() && !l_2_n.empty()) {
			sum += l_1_n.front() * l_2_n.front();
			l_1_n.pop_front();
			l_2_n.pop_front();
			e = 1;
		}
		if (f == 0 && e == 0) {
			break;
		}
	}
	printf("%d", sum);
	return 0;
}
