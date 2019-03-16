#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
constexpr int mod = 1000000007;
int main() {
	string str;
	cin >> str;
	int size = str.length();
	vector<int>left_P_num(size, 0);
	for (int i = 0;i < size;++i) {
		if (i != 0) {
			left_P_num[i] = left_P_num[i - 1];
		}
		if (str[i] == 'P')
			++left_P_num[i];
	}
	int right_T_num = 0;
	long long sum = 0;
	for (int i = size - 1;i > 0;--i) {
		if (str[i] == 'T')
			++right_T_num;
		if (str[i] == 'A')
			sum = (sum + left_P_num[i] * right_T_num)  % mod;
	}
	printf("%lld", sum);
	return 0;
}
