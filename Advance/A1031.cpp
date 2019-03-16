#include <cstdio>
#include <string>
#include <iostream>
#include <cmath>
using namespace std;
int main() {
	string str;
	cin >> str;
	int n = floor((str.size() + 2) / 3);
	int n1 = 0;
	int n2 = 0;
	int n3 = 0;
	n1 = n3 = n;
	n2 = str.size() + 2 - 2 * n;
	auto s = str.c_str();
	int index = 0;
	char res[n1][n2];
	for (int i = 0;i < n1;++i) {
		for (int j = 0; j < n2;++j) {
			res[i][j] = ' ';
		}
	}
	for (int i = 0;i < n1;++i) {
		res[i][0] = s[index++];
	}
	for (int i = 1;i < n2;++i) {
		res[n1 - 1][i] = s[index++];
	}
	for (int i = n3 - 2; i >= 0;--i) {
		res[i][n2 - 1] = s[index++];
	}
	int flag = 0;
	for (const auto &item : res) {
	  if (flag) cout << endl;
		for (const auto &item2 : item) {
			cout << item2;
		}
		flag = 1;
	}
	return 0;
}
