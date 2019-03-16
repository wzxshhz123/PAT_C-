#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int n = 0;
	cin >> n;
	vector<string> vec;
	getchar();
	int min_size = 257;
	string min;
	for (int i = 0;i < n;++i){
		string str;
		getline(cin,str);
		if (min_size > str.size()) {
			min_size = str.size();
			min = str;
		}
		vec.push_back(str);
	}
	string res;
	
	reverse(min.begin(),min.end());
	for (int i = 0;i < vec.size();++i) {
		reverse(vec[i].begin(),vec[i].end());
	}
	for (int i = 0;i < min_size;++i) {
		char ch = min[i];
		int flag = 1;
		for (int j = 0;j < vec.size();++j) {
			if (vec[j][i] != ch) {
				flag = 0;
				break;
			}
		}
		if (flag)
			res.push_back(min[i]);
		else 
			break;
	}
	if (!res.empty()) {
		reverse(res.begin(),res.end());
		cout << res;
	}
	else 
		cout << "nai";
	return 0;
}
