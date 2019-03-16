#include <string>
#include <algorithm>
#include <iostream>
#include <cctype>
#include <iterator>
#include <vector>
using namespace std;
int main() {
	vector<string> str;
  char ch = '\n';
	int i = 0;
	string s;
	while(cin >> s && s != string(&ch)) {
	  str.push_back(s); 
	  ++i;
	}
	int n = 0;
	reverse(str.begin(),str.end());
	int flag = 0;
	for(auto item : str) {
		if (flag) cout << " ";
		cout << item;
		flag = 1;
	}
	return 0;
}
