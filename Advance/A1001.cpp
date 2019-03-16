#include <iostream>
#include <string>
#include <stack>
#include <cctype>
using namespace std;
int main() {
	long long a = 0;
	long long b = 0;
	stack<char>s;
	cin >> a >> b;
	long long sum = a + b;
	if (sum < 0) 
		cout <<'-';
	sum = abs(sum); 
	string str = to_string(sum);
	int num = 0;
	for (auto iter = str.rbegin();iter != str.rend();++iter) {
		if (num == 3) {
			s.push(',');
			num = 0;
		}
		s.push(*iter);
		++num;
	}
	while(!s.empty()) {
		cout << s.top();
		s.pop();
	}
	return 0;
}
