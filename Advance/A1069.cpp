#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main() {
	string str;
	cin >> str;
	int flag = 0;
	int max = 0;
	int min = 0;
	int n = 0;
	while (str.length() != 4)
		str.push_back('0');
	while (true) {
		sort(str.begin(), str.end());
		min = stoi(str);
		sort(str.begin(), str.end(), greater<char>());
		max = stoi(str);
		n = max - min;
		if (flag)
			printf("\n");
		flag = 1;
		printf("%04d - %04d = %04d", max, min, n);
		if (n == 0 || n == 6174)
			break;
		str = to_string(n);
		while (str.length() != 4)
			str.push_back('0');
	}
	return 0;
}
