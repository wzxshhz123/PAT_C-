#include <iostream>
#include <list>
#include <string>
#include <algorithm>
using namespace std;
void Show(list<int> &res) {
	for (auto iter = res.rbegin();iter != res.rend();++iter) {
		cout << *iter;
	} 
}
int main() {
	string bign;
	cin >> bign;
	int b = 2;
	reverse(bign.begin(), bign.end());
	int carry = 0;
	list<int> res;
	for (int i = 0;i < bign.length();++i) {
		int x = bign[i] - '0';
		int temp = x * b + carry;
		res.push_back(temp % 10);
		carry = temp / 10;
	}
	if (carry != 0) {
		res.push_back(carry);
	}
	if (res.size() != bign.size()) {
		printf("No\n");
		Show(res);
		return 0;
	}
	int count[10] = {0};
	for (auto item : res) {
		--count[item];
	}
	for (auto item : bign) {
		int i = item - '0';
		++count[i];
	}
	int flag = 1;
	for (int i = 0;i < 9;++i) {
		if (count[i] != 0) {
			printf("No\n");
			flag = 0;
			break;
		}
	}
	if (flag)
		printf("Yes\n");
	Show(res);
	return 0;
}
