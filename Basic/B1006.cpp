#include <iostream>
#include <string>
using namespace std;
int main() {
	string str;
	cin >> str;
//	printf("%d",str.size());
	if (str.size() == 3) {
		int b = str[0] - '0';
		for (int i = 0;i < b;++i){
				cout << "B"; 
		}	
		int s = str[1] - '0';
		for (int i = 0;i < s;++i){
				cout << "S"; 
		}	
		int g = str[2] - '0';
		for (int i = 1;i <= g;++i){
				cout << i; 
		}	
	}
	else if (str.size() == 2) {
    int s = str[0] - '0';
		for (int i = 0;i < s;++i){
				cout << "S"; 
		}	
		int g = str[1] - '0';
		for (int i = 1;i <= g;++i){
				cout << i; 
		}	
	}
	else if (str.size() == 1) {
		int g = str[0] - '0';
		for (int i = 1;i <= g;++i){
				cout << i; 
		}	
	}
	return 0;
}
