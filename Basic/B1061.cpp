#include <iostream>
#include <vector>
using namespace std;
struct Ques {
	int ans = -1;
	int score = 0;
};
int main() {
	int n = 0;
	int m = 0;
	scanf("%d %d", &n, &m);
	vector<Ques>vec;
	for (int i = 0;i < m;++i) {
		Ques e;
		int s = 0;
		scanf("%d", &s);
		e.score = s;
		vec.push_back(e);
	}
	for (int i = 0;i < m;++i) {
		int an = -1;
		scanf("%d", &an);
		vec[i].ans = an;
	}
	vector<int>stu;
	for (int i = 0;i < n;++i) {
		int sum = 0;
		for (int j = 0;j < m;++j) {
			int e = -1;
			scanf("%d", &e);
			if (e == vec[j].ans) {
				sum += vec[j].score;
			}
		}
		stu.push_back(sum);
	}
	int flag = 0;
	for (auto item : stu) {
		if (flag)
			printf("\n");
		flag = 1;
		printf("%d", item);
	}
	return 0;
}
