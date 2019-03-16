#include <iostream>
#include <string>
#include <cmath>
#include <cctype>
#include <algorithm>
using namespace std;
int main() {
	string str;
	cin >> str;
	if (str[0] != '+') {
		printf("%c",'-');
	}
	str.erase(str.begin());
	int pos = str.find("E") + 1;
	int exp = stoi(string(str.cbegin() + pos,str.cend()));
	string l = string(str.cbegin(),str.cbegin() + pos - 1);
	l = l.erase(l.find("."),l.find("."));

	if (exp == 0) {
		cout << string(str.cbegin(),str.cbegin() + pos - 1);
		return 0;
	} 
	else if (exp < 0) {
		cout << "0.";
		for (int i = 0;i < abs(exp) - 1;++i) {
			cout << "0";
		}
		cout << l;
	}
	else if (exp > 0) {
		int j = 0;
		int flag = 0;
		int i = 0;
		if (l[0] == '0')
				i = 1;
		for (;i <= exp;++i) {
			if (i < l.size()) {
				cout << l[i];
				++j;
			}
			else {
				printf("0");
			}
		}
		l.size() - 1  > exp ? printf(".") : flag = 1;
		if (!flag) {
			for (int i = j;i < l.size();++i) {
				cout << l[i];
			}
		}
	}
	return 0;
}

