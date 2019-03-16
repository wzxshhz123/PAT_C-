#include <iostream>
#include <string>
#include <map>
using namespace std;
int main() {
	map<int,int>v;
	string str;
	cin >> str;
	for (const auto &item : str) {
		int n = item - '0';
		++v[n];
	} 
	for(const auto &item : v) {
		cout << item.first << ":" << item.second << endl;
	}
}
