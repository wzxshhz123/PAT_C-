#include <iostream>
#include <algorithm>
#include <string>
#include <iterator>
using namespace std;
void PreDeal(string &str, int &e) {
	while (*str.begin() == '0') {
		str.erase(str.begin());
	}
	
	if (*str.begin() == '.') {
		str.erase(str.begin());
		if (str.find_first_not_of('0') != string::npos)
			while (*str.begin() == '0') {
				str.erase(str.begin());
				--e;
			}
	}
	else {
		if (str.find('.') != string::npos) {
			int pos = str.find('.');
			e = pos;
			str.erase(pos,1);
		}
		else {
			e = str.length();
		}
	}
	
}
int main() {
	int n = 0;
	scanf("%d", &n);
	string str1;
	string str2;
	cin >> str1;
	cin >> str2;
	int e1 = 0;
	int e2 = 0;
	PreDeal(str1, e1);
	PreDeal(str2, e2);
//	cout << str1 << " " << e1 << endl;
//	cout << str2 << " " << e2 << endl;
	auto sub_str1 = str1.substr(0, n);
	auto sub_str2 = str2.substr(0, n);
//	sub_str1.insert(back_inserter(sub_str1), n - sub_str1.size(), '0');
	while (sub_str1.size() < n) {
		sub_str1.push_back('0');
	}
	while (sub_str2.size() < n) {
		sub_str2.push_back('0'); 
	}
//	sub_str2.insert(n - sub_str2.size(), '0');
//	cout << sub_str1 << " " << sub_str2 << endl;
	if (sub_str1 == sub_str2 && e1 == e2) {
		printf("YES");
		cout << " 0." << sub_str1 << "*10^" << e1;
	}
	else {
		printf("NO");
		cout << " 0." << sub_str1 << "*10^" << e1;
		cout << " 0." << sub_str2 << "*10^" << e2;
	}
	return 0;
}
