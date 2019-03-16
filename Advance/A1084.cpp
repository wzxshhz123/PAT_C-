#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;
int main() {
	string str_1;
	string str_2;
	bool hash[85] = {false};
	getline(cin, str_1);
	getline(cin, str_2);
	for (auto iter = str_1.begin();iter != str_1.end();++iter) {
		char ch_1 = *iter;
		if (islower(ch_1)) {
			ch_1 -= 32;
		}
		int flag = 0;
		for (auto iter_2 = str_2.begin();iter_2 != str_2.end();++iter_2) {
			char ch_2 = *iter_2;
			if (islower(ch_2)) {
				ch_2 -= 32;
			}
			if (ch_1 == ch_2) {
				flag = 1;
				break;
			}
		}
		if (!flag && hash[ch_1] == false) {
			cout << ch_1;
			hash[ch_1] = true;
		}
	}
	return 0;
} 
