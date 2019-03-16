#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
vector<int>score;
struct Stu {
	int id;
	int problem[5] = {-2, -2, -2, -2, -2};
	int rank = 0;
	int sum = 0;
	int exist = 0;
	int perfect = 0;
};
Stu stus[100005];
bool Cmp(const Stu &a, const Stu &b) {
	if (a.sum != b.sum)
		return a.sum > b.sum;
	else if (a.perfect != b.perfect)
		return a.perfect > b.perfect;
	else 
		return a.id < b.id;
}
int main() {
	int n = 0;
	int k = 0;
	int m = 0;
	scanf("%d %d %d", &n, &k, &m);
	for (int i = 0;i < k;++i) {
		int e = 0;
		scanf("%d", &e);
		score.push_back(e);
	}
	
	while (m--) {
		int id = 0;
		int problem = 0;
		int score = 0;
		scanf("%d %d %d", &id, &problem, &score);
		bool s = score > stus[id - 1].problem[problem -1];
		if (s)
			stus[id - 1].problem[problem - 1] = score;
		stus[id - 1].id = id;
	}
	for(auto iter = begin(stus);iter != begin(stus) + n;++iter) {
		for (int i = 0;i < k;++i) {
			if (iter->problem[i] != -2) {
				if (iter->problem[i] == score[i]){
					++iter->perfect;
				}
				if (iter->problem[i] != -1) {
					iter->sum += iter->problem[i];
					iter->exist = 1;
				}
				
			}
		}
	}
	sort(begin(stus),begin(stus) + n,Cmp);
	stus[0].rank = 1;
	for (int i = 1;i < n;++i) {
		if (stus[i].sum == stus[i - 1].sum) {
			stus[i].rank = stus[i - 1].rank;
		}
		else {
			stus[i].rank = i + 1;
		}
	}
	int flag = 0;
	for(int i = 0;i < n;++i) {
		if (stus[i].exist == 1) {
			if (flag)  printf("\n");
			printf("%d %05d %d", stus[i].rank, stus[i].id, stus[i].sum);
			for (int j = 0;j < k;++j) {
				if (stus[i].problem[j] == -2)
					printf(" -");	
				else if (stus[i].problem[j] == -1)
					printf(" 0");
				else
					printf(" %d", stus[i].problem[j]);
			}
			flag = 1;
		}
	}
	return 0;
}
