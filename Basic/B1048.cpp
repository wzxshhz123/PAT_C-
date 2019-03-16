#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main() {
	stack<char>s;
	string str_1;
	string str_2;
	cin >> str_1 >> str_2;
	if (str_2.size() < str_1.size()) {
		int n = str_1.size() - str_2.size();
		int i = 0;
		for (auto iter = str_2.begin();i < n;++iter,++i) {
			str_2.insert(str_2.begin(),'0');
		}	
	}
	auto iter_1 = str_1.rbegin();
	auto iter_2 = str_2.rbegin();
	int num = 1;
	for(;iter_1 != str_1.rend() && iter_2 != str_2.rend();++iter_1,++iter_2) {
		if (num % 2 == 1) {
			int res = (*iter_1 - '0') + (*iter_2 - '0');
			res %= 13;
			switch (res) {
				case 10:
					s.push('J');
					break;
				case 11:
					s.push('Q');
					break;
				case 12:
					s.push('K');
					break;
				default:
					s.push(res + '0');
					break;
			}
		}
		else {
				int res = (*iter_2 - '0') - (*iter_1 - '0');
				if (res < 0)
					res += 10;
				s.push(res + '0');
		}
		++num;
	}
	for(;iter_2 != str_2.rend();++iter_2) {
		s.push(*iter_2);
	}

	while (!s.empty()) {
		cout << s.top();
		s.pop(); 
	} 
	return 0;
}
