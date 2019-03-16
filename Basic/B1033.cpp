#include <iostream>
#include <string>
#include <unordered_map>
#include <cctype>
using namespace std;
unordered_map<char, bool> m;
int main() {
	string str_1;
	string str_2;
	getline(cin, str_1);
	getline(cin, str_2);
	int flag = 0;
	for (auto iter = str_1.begin();iter != str_1.end();++iter) {
		char ch_1 = *iter;
		if (ch_1 == '+') {
			flag = 1;
			continue;
		}
		if (isupper(ch_1)) {
			ch_1 += 32;
		}
		m[ch_1] = true;
	}
	for (auto iter_2 = str_2.begin();iter_2 != str_2.end();++iter_2) {
			char ch_2 = *iter_2;
			if (isupper(ch_2)) {
				char temp = ch_2 + 32;
				if (m[temp] != true && flag == 0) 
					printf("%c", ch_2);
			}
			else if (m[ch_2] != true && ch_2 != '+') {
				printf("%c", ch_2);
			}
		}
	return 0;
} 
