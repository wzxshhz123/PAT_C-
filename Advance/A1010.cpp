#include <iostream>
#include <string>
#include <unordered_map>
#include <cmath>
#include <algorithm>
using namespace std;
unordered_map<char, int>m;
long long Trans(string &lhs, int now) {
	long long sum = 0;
	int i = 0;
	for (auto iter = lhs.rbegin();iter != lhs.rend();++iter, ++i)
		sum += m[*iter] * pow(now, i);
	return sum;
}
int FindLeft(string &lhs) {
	int left = -1;
	for (auto item : lhs) {
		left = max(left, m[item]);
	}
	return left;
}
int main() {
	string n1;
	string n2;
	int tag = 0;
	int radix = 0;
	cin >> n1 >> n2 >> tag >> radix;
	if (tag == 2)
		swap(n1, n2);
	for (char ch = '0', i = 0;ch <= '9';++ch, ++i) {
		m[ch] = i;
	}
	for (char ch = 'a', i = 10;ch <= 'z';++ch, ++i) {
		m[ch] = i;
	}
	long long t = 0;
	if (radix != 10)
		t = Trans(n1, radix);
	else
		t = stold(n1);
//	cout << t;
	long long left = FindLeft(n2) + 1;
	long long right = max(t, left) + 1;
	
	long long mid = 0;
	while (true) {
		mid = (left + right) / 2;
//		cout << mid;
		long long a = Trans(n2, mid);
		int flag = -2;
		if (a < 0)
			flag = 1;
		else if (a > t)
			flag = 1;
		else if (a < t)
			flag = -1;
		else
			flag = 0;
		if (flag == 1) {
			right = mid - 1;
		}
		else if (flag == -1) {
			left = mid + 1;
		}
		else
			break;
		if (left > right) {
			printf("Impossible");
			return 0;
		}
	}
	printf("%lld", mid);
	return 0;
}
