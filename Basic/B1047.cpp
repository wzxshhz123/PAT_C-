#include <iostream>
#include <unordered_map>
using namespace std;
int main() {
	int n = 0;
	scanf("%d", &n);
	unordered_map<int, int>m;
	while (n--) {
		int group = 0;
		int index = 0;
		int grade = 0;
		scanf("%d-%d %d", &group, &index, &grade);
		m[group] += grade;
	}
	int group = 0;
	int max = -1;
	for (auto iter = m.begin();iter != m.end();++iter) {
		if (iter->second > max) {
			max = iter->second;
			group = iter->first;
		}
	}
	printf("%d %d", group, max);
	return 0;
}
