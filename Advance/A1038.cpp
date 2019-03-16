#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int n = 0;
	scanf("%d", &n);
	vector<string>vec;
	while (n--) {
		string str;
		cin >> str;
		vec.push_back(str);
	}
	auto Cmp = [](string &lhs, string &rhs) {
		return lhs + rhs < rhs + lhs;
	};
	sort(vec.begin(), vec.end(), Cmp);
	string res;
	for(auto item : vec) {
		res += item;
	}
	while (res.size() != 0 && res[0] == '0') {
			res.erase(res.begin());
	}
	if (res.empty())
		cout << 0;
	else
		cout << res;
	return 0;
}
