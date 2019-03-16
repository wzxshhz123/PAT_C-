#include <iostream>
#include <vector>
using namespace std;
int main() {
	int n = 0;
	scanf("%d", &n);
	int array[10005] = {0};
	vector<int> vec;
	while (n--) {
		int e = 0;
		scanf("%d", &e);
		if (array[e] == 0) 
			vec.push_back(e);
		++array[e];
	}
	int flag = 0;
	for (auto iter = vec.begin();iter != vec.end();++iter) {
		if (array[*iter] == 1) {
			printf("%d", *iter);
			flag = 1;
			break;
		}
	}
	if (!flag)
		printf("None");
	return 0;
}
