#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;
int main() {
	string str_1;
	string str_2;
	cin >> str_1;
	cin >> str_2;
	unordered_map<char, int>m;
//	unordered_map<char, bool>s;
	for (auto iter = str_1.begin();iter != str_1.end();++iter) {
		++m[*iter];
	}
	int sum = 0;
	int minus = 0;
//	for (auto item : m) {
//		cout << item.first << " " << item.second << " ";
//	}
	for (auto iter = str_2.begin();iter != str_2.end();++iter) {
//		printf("%d\n", m.count(*iter));
		if (m.count(*iter) != 0) {
			if (m.at(*iter)) {
				--m[*iter];
				++sum;
			}
			else 
				++minus;
		}
		else {
			++minus;
		}
	}
//			cout << sum << " " << str_2.length();

	if (sum >= str_2.length()) {
//		cout << sum << " " << str_2.length();
		printf("Yes %d", str_1.size() - str_2.size());
	}
	else {
		printf("No %d", minus);
	}
	
	return 0;
}
