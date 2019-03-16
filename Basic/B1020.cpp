#include <iostream>
#include <algorithm>
#include <iterator>
using namespace std;
int main() {
	int n = 0;
	double d = 0;
	scanf("%d %lf", &n, &d);
	int ns = n;
	double base[1005] = {0};
	double m[1005] = {0};
	int i = 0;
	while (n--) {
		double e = 0;
		scanf("%lf", &e);
		base[i] = e;
		++i;
	}
	n = ns;
	i = 0;
	while (n--) {
		double e = 0;
		scanf("%lf", &e);
		m[i] = e;
		++i;
	}
	pair<int, double> p[1005];
	for (int i = 0;i < ns;++i) {
		double per = m[i] / base[i];
		p[i] = make_pair(i, per);
	}
	double sum = 0;
	auto Cmp = [](pair<int, double> &a, pair<int, double> &b) {
		return a.second > b.second;
	};
	sort(begin(p), begin(p) + ns, Cmp);
	i = 0;
	while (d != 0 && i < ns) {
		if (base[p[i].first] > 0) {
			if (base[p[i].first] >= d) {
				sum += d * p[i].second;
				break;
			}
			else {
				sum += base[p[i].first] * p[i].second;
				d -= base[p[i].first];
				base[p[i].first] = 0;
			}
		}
		else {
			++i;
		}
	}
	printf("%.2lf", sum);
	
	return 0;
} 
