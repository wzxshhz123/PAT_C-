#include <iostream>
#include <vector>
using namespace std;
int main() {
	int n = 0;
	int d = 0;
	scanf("%d %d", &d, &n);
	vector<int>vec;
	vector<int>temp;
	vec.push_back(d);
	--n;
	while (n--) {
		int count = 1;
		temp.push_back(vec[0]);
		for (int i = 1;i < vec.size();++i) {
			if (vec[i] == vec[i - 1]) {
				++count;
			}
			else {
				temp.push_back(count);
				temp.push_back(vec[i]);
				count = 1;
			} 
		}
		temp.push_back(count);
		vec = move(temp);
	}
	for (auto iter = vec.begin();iter != vec.end();++iter)
		printf("%d", *iter);
	return 0;
} 
