#include <climits>
#include <list>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;
int main() {
	string bign;
	int step = 0;
	cin >> bign;
	scanf("%d", &step);
	int count = 0;
	for (int i = 0;i < step;++i) {
		string r = bign;
		reverse(r.begin(),r.end());
		if (r == bign) {
			cout << r << '\n' << count;
			return 0;
		}
		string str;
		auto iter1 = bign.rbegin();
		auto iter2 = r.rbegin();
		int carry = 0;
		for (; iter1 != bign.rend();++iter1, ++iter2) {
			int x = *iter1 - '0';
			int y = *iter2 - '0';
			int temp = x + y + carry;
			int r = temp % 10;
			carry = temp / 10;
			char ch = r + '0';
			str.push_back(ch);
		}
		if (carry != 0) {
			char ch = carry + '0';
			str.push_back(ch);
		}
		++count;
		reverse(str.begin(), str.end());
		bign = str;
//		cout << bign << endl;
	}
	cout << bign << '\n' << count;
	return 0;
}
