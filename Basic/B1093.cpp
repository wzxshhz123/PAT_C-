#include <iostream>
#include <string>
using namespace std;
char m[150] = {0};
string s;
int main() {
	string str1;
	string str2;
	getline(cin, str1);
	getline(cin, str2);
	for (auto iter = str1.begin();iter != str1.end();++iter) {
		if (m[*iter] == false) {
			s.push_back(*iter);
			m[*iter] = true;
		}
	}
	for (auto iter = str2.begin();iter != str2.end();++iter) {
		if (m[*iter] == false) {
			m[*iter] = true;
			s.push_back(*iter);
		}
	}
	printf("%s", s.c_str());
	return 0;
} 
