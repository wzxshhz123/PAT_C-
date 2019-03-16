#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;
int main() {
	unordered_map<char, int>m;
	string str;
	getline(cin, str);
	for (auto iter = str.begin();iter != str.end();++iter) {
		if (isupper(*iter))
			*iter += 32;
		if (isalpha(*iter))
			++m[*iter];
	}
	char ch = 0;
	int max = -1;
	for (auto iter = m.begin();iter != m.end();++iter) {
		if (iter->second > max) {
			max = iter->second;
			ch = iter->first;
		}
		else if (iter->second == max && ch > iter->first) {
			ch = iter->first;
		}
	}
	printf("%c %d", ch, max);
	return 0;
}
