#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int n = 0;
	scanf("%d", &n);
	vector<int> vec;
	while(n--) {
		int e = 0;
		scanf("%d", &e);
		vec.push_back(e);
	}
	vector<int>res;
	unordered_map<int, bool>m;
	for (auto iter = vec.begin();iter != vec.end();++iter) {
		int num = *iter;
		while (true) {
			if (num % 2 == 0) {
				num /= 2;
				m[num] = true;
				continue;
			}
			if (num == 1) {
				m[num] = true;
				break;
			}
			num = (3 * num + 1) / 2;
			m[num] = true;
			continue;
		}
	}
//	for (auto item : m) {
//		cout << item.first << endl;
//	}
	for (auto i = vec.begin();i != vec.end();++i) {
		if (m.count(*i) == 0) {
			res.push_back(*i);
		}
	}
	auto Cmp = [](int a, int b) {
		return a > b;
	};
//	for (auto item : res) {
//		cout << item << endl;
//	}
	sort(res.begin(),res.end(),Cmp);
	int flag = 0;
	for (auto iter = res.begin();iter != res.end();++iter) {
		if (flag)
			printf(" ");
		printf("%d", *iter);
			flag = 1;
	}
	return 0;	
}
