#include <iostream>
#include <string>
using namespace std;
char *array[] = {"zero","one","two","three","four","five","six","seven","eight","nine"}; 
int main() {
	string str;
	cin >> str;
	long long sum = 0;
	for (const auto &item : str) {
		sum += item - '0';
	}
	string res = to_string(sum);
	int flag = 0;
	for (const auto &item : res) {
		if (flag)  cout << " ";
		cout << array[item - '0'];
		flag = 1;
	}
	return 0;
}
