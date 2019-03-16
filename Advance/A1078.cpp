#include <iostream>
#include <vector>
#include <cmath>
//#include <unordered_map>
bool hash_table[10005] = {0};
using namespace std;
bool IsPrime (int n) {
	if (n <= 1)
		return false;
	int num = sqrt(1.0 * n);
	for (int i = 2;i <= num;++i) {
		if (n % i == 0)
			return false;
	}
	return true;
}
int main() {
	int size = 0;
	int n = 0;
	scanf("%d %d", &size, &n);
	while (!IsPrime(size)) {
		++size;
	}
	vector<int>vec;
	vector<int>res;
	while (n--) {
		int e = 0;
		scanf("%d", &e);
		vec.push_back(e);
	}
	int flag = 0;
	for (auto item : vec) {
		if (flag)
			printf(" ");
		flag = 1;
		if (hash_table[item % size] == false) {
			hash_table[item % size] = true;
//			res.push_back(item % size);
			printf("%d", item % size);
		}
		else {
			int step = 1;
			int f = 0;
			while (step < size) {
				auto now = item + step * step;
				if (hash_table[now % size] == false) {
					hash_table[now % size] = true;
					printf("%d", now % size);
					f = 1;
					break;
				}
				else {
					++step;
				}
			}
			if (f == 0)
				printf("-");
		}
	}
	return 0;
}
