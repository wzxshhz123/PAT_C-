#include <iostream>
#include <vector> 
#include <algorithm>
using namespace std;
int main() {
	int n = 0;
	scanf("%d", &n);
	vector<int> vec;
	while (n--) {
		int e = 0;
		scanf("%d", &e);
		vec.push_back(e);
	}
	int num = 0;
	vector<int> left(vec.size());
	vector<int> right(vec.size());
	left[0] = vec[0];
	right[right.size() - 1] = vec[vec.size() - 1];
	int max = left[0];
	int min = right[right.size() - 1];
	
	for (int i = 1;i < vec.size();++i) {
		if (vec[i] > max) {
			left[i] = vec[i];
			max = left[i];
		}
		else {
			left[i] = left[i - 1];
		}
	}
	
	for (int i = vec.size() - 2;i > -1;--i) {
		if (vec[i] < min) {
			right[i] = vec[i];
			min = right[i];
		}
		else {
			right[i] = right[i + 1];
		}
	}
	vector<int>res;
	for (int i = 0;i < vec.size();++i) {
		if (vec[i] >= left[i] && vec[i] <= right[i]) 
			res.push_back(vec[i]);
	}
	printf("%d\n", res.size());
	if (res.size() == 0)
		printf("\n");
	int flag = 0;
	sort(res.begin(), res.end());
	for (auto item : res) {
		if (flag)
			printf(" ");
		flag = 1;
		printf("%d", item);
	}
	return 0;
}
