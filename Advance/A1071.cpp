#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;
int main() {
	string str;
	getline(cin, str);
	int i = 0;
	unordered_map<string, int>h;
	while (i < str.size()) {
		string word;
		while (i < str.size() && (isalpha(str[i]) || isdigit(str[i]))) {
			if (isupper(str[i])) {
				char ch = tolower(str[i]);
				word += ch;
			}
			else
				word += str[i];
			++i;
		}
		if (word.size() > 0) {
			++h[word];
		}
		while (!isalpha(str[i]) && !isdigit(str[i])) {
			++i;
		}
	}
	string s;
	int x = -1;
	for (auto item : h) {
		if (item.second > x) {
			s = item.first;
			x = item.second;
		}
	}
	printf("%s %d", s.c_str(), x);
	return 0;
}
