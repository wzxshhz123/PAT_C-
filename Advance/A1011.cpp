#include <cstdio>
#include <vector>
#include <utility>
using namespace std;
int rate[4];
int main() {
	int t = 3;
	vector<pair<int,float>> vec;
	while (t--) {
		int n = 3;
		int index = -1;
		float max = -1;
		for(int i = 0; i < 3;++i) {
			float s = 0;
			scanf("%f", &s);
			if (s > max) {
				index = i;
				max = s;
			}
		}
		vec.push_back(make_pair(index,max));
	}
	float res = 1;
	int flag = 0;
	for(const auto &item : vec) {
		if (flag) printf(" ");
		if (item.first == 0) {
			printf("W");
		}
		else if (item.first == 1) {
			printf("T");
		}
		else {
			printf("L");
		}
		res *= item.second;
		flag = 1;
	}
	printf(" %.2f",2 * (res * 0.65 -1));
	return 0;
}
