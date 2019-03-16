#include <iostream>
#include <string>
#include <iterator>
using namespace std;
int main() {
	string str;
	cin >> str;
	if (str.length() ==  1) {
		printf("1");
		return 0;
	}
	str.insert(0, "a");
//	cout << str;

	int a = 1;
	int sum = 0;
	for (int i = str.length() - 1;i > 0;--i) {
		auto left = string(str.begin() + 1, str.begin() + i);
		auto right = string(str.begin() + i + 1, str.end());
		int left_num = 0;
		int right_num = 0;
		if (!left.empty()) {
			left_num = stoi(left);
		}
		if (!right.empty()) {
			right_num = stoi(right);
		}
		int now = str[i] - '0';
		if (now == 0) {
			sum += left_num * a;
		}
		else if (now >= 2) {
			sum += (left_num + 1) * a;
		}
		else if (now == 1) {
			sum += (left_num * a) + right_num + 1;
		}
		a *= 10;
//		cout << left << endl;
	}
	printf("%d", sum);
	return 0;
}
