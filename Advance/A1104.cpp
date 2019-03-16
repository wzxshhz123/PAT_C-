#include <iostream>
#include <vector>
using namespace std;
int main() {
	int n = 0;
	scanf("%d", &n);
	int ns = n;
	vector<double>vec;
	vec.push_back(-1);
	while (n--) {
		double e = 0;
		scanf("%lf", &e);
		vec.push_back(e);
	}
//	for (auto item : vec) {
//		cout << item << " ";
//	}
	double sum = 0;
	for (long long i = 1;i < vec.size();++i) {
		double num =  i * (ns - i + 1) * vec[i];
		sum += num;
	}
//	cout << sum;
	printf("%.2lf", sum);
	return 0;
}

