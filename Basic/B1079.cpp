#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
bool IsPaNumer(string &str) {
	if (str.length() < 2 && str[0] == '0')
		return true;
	if (str.length() < 2)
		return true;
	int k = str.length() - 1;
	for (int i = 0;i < str.length();++i) {
		if (i >= k - i)
			break;
		if (str[i] != str[k - i]) 
			return false;
	}
	return true;
}
string Add(const string &lhs, const string &rhs) {
	int carry = 0;
	auto riter1 = lhs.rbegin();
	auto riter2 = rhs.rbegin();
	string res;
	for (;riter1 != lhs.rend() && riter2 != rhs.rend();++riter1, ++riter2) {
		int temp = (*riter1 - '0') + (*riter2 - '0') + carry;
		res.push_back(temp % 10 + '0');
		carry = temp / 10;
	}
	if (carry != 0)
		res.push_back(carry % 10 + '0');
	reverse(res.begin(), res.end());
	return res;
}
int main() {
	string num;
	cin >> num;
	if (IsPaNumer(num)) {
		printf("%s is a palindromic number.", num.c_str());
		return 0;
	}
	int n = 0;
	while(!IsPaNumer(num) && n < 10) {
		auto rev = num;
		reverse(rev.begin(), rev.end());
		auto plus = Add(num, rev);
		printf("%s + %s = %s\n", num.c_str(), rev.c_str(), plus.c_str());
		num = move(plus);
		++n;
	}
	if (IsPaNumer(num)) {
		printf("%s is a palindromic number.", num.c_str());
	}
	else {
		printf("Not found in 10 iterations.");
	}
}
