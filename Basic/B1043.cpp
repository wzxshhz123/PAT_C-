#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
int main() {
	string str;
	cin >> str;
	unordered_map<char, int> m;
	for (auto iter = str.begin();iter != str.end();++iter) {
		if (*iter == 'P' || *iter == 'A' || *iter == 'T' || *iter == 'e' || *iter == 's' || *iter == 't')
			++m[*iter];
	}
	auto iter = m.begin();
	while (m['P'] > 0 || m['A'] > 0 || m['T'] > 0 || m['e'] > 0 || m['s'] > 0 || m['t'] > 0) {
		if (m['P'] > 0) {
			printf("%c", 'P');
			--m['P'];
		}
		if (m['A'] > 0) {
			printf("%c", 'A');
			--m['A'];
		}
		if (m['T'] > 0) {
			printf("%c", 'T');
			--m['T'];
		}
		if (m['e'] > 0) {
			printf("%c", 'e');
			--m['e'];
		}
		if (m['s'] > 0) {
			printf("%c", 's');
			--m['s'];
		}
		if (m['t'] > 0) {
			printf("%c", 't');
			--m['t'];
		}
	}
	return 0;
}
