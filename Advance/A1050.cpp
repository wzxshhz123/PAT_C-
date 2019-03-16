#include <cstring>
#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;
int main() {
	string str1;
	getline(cin, str1);
	unordered_map<char, bool>m;
	char ch = '\0';
	while((ch = getchar()) != '\n') {
		m[ch] = true;
	}
	for (int i = 0;i < str1.size();++i) {
		if (m.count(str1[i]) == 0)
			printf("%c", str1[i]);
	}
	return 0;
}
