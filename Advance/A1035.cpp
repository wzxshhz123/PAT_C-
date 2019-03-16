#include <iostream>
#include <string>
#include <vector>
#include <utility>
using namespace std;
int main() {
	int ns = 0;
	cin >> ns;
	int n = ns;
	vector<pair<string,string>>vec;
	vector<pair<string,string>>res;
	while (ns--) {
		string name;
		string pass;
		cin >> name >> pass;
		vec.push_back(make_pair(name,pass));
	}
	int mod_num = 0;
	for (auto &item : vec) {
		int flag = 0;
		for (auto iter = item.second.begin();iter != item.second.end();++iter) {
			int pos = iter - item.second.begin();
			if (*iter == '1') {
				flag = 1;
				item.second.replace(pos, 1, 1, '@');
			}
			else if (*iter == '0') {
				flag = 1;
				item.second.replace(pos, 1, 1, '%');
			}
			else if (*iter == 'l') {
				flag = 1;
				item.second.replace(pos, 1, 1, 'L');
			}
			else if (*iter == 'O') {
				flag = 1;
				item.second.replace(pos, 1, 1, 'o');
			}
		}
		if (flag) {
			++mod_num;
			res.push_back(item);
		}
	}
	if (n == 1 && res.empty()) {
		cout << "There is 1 account and no account is modified";
	}
	else if (res.empty()) {
		cout << "There are " << n << " account and no account is modified";
	}
	else {
		cout << mod_num;
		for (const auto &item : res) {
			cout << endl;
			cout << item.first << " " << item.second;
		}
	}
	return 0;
}
