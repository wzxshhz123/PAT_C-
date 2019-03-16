#include <iostream>
#include <algorithm>
#include <string>
#include <list>
using namespace std;
int main() {
	string bign;
	int b = 0;
	cin >> bign;
	scanf("%d", &b);
	
//	string res;
	list<int> res;
	int r = 0;
	int carry = 0;
	for (int i = 0;i < bign.length();++i) {
		int x = bign[i] - '0';
		int temp = r * 10 + x;
		if (temp < b) {
			res.push_back(0);
			r = temp;
		} 
		else {
//			char ch = temp / b;
			res.push_back(temp / b);
			r = temp % b;
		}
	}
	while (res.front() == 0 && res.size() > 1) {
		res.pop_front();
	}
	int flag = 0;
	for (auto item : res) { 
			cout << item;
			flag = 1;
	}
	if (flag)
		cout << " ";
	cout << r;
	return 0;
}
