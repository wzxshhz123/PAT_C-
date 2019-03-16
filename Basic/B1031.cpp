#include <iostream>
#include <string>
#include <vector>
using namespace std;
int arr[] = {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
char x[] = {'1','0','X','9','8','7','6','5','4','3','2'};
int main() {
	int n = 0;
	cin >> n;
	vector<string> error;
	while(n--) {
		string str;
		cin >> str;
		int sum = 0;
		int i = 0;
		int flag = 1;
		for (auto iter = str.cbegin();iter != str.cend() - 1;++iter) {
			if (*iter >= '0' && *iter <= '9') {
				int n = *iter - '0';
				sum = sum + (arr[i] * n);
				++i;
			}
			else {
				error.push_back(str);
				flag = 0;
				break;
			}
		}
		if (flag) {
			sum = sum % 11;
			sum = x[sum];
			if (sum != *(str.end() - 1))
				 error.push_back(str);
		}
	}
	if (error.empty()) {
		cout <<  "All passed";
	}
	else {
		for (const auto &item : error) {
			cout << item << endl;
		}
	}
	return 0;
}
