#include <iostream>
#include <cmath>
#include <string>
using namespace std;
bool IsPrime(int n) {
	if (n <= 1)
		return false;
	int num = (int)sqrt(1.0 * n);
	for (int i = 2;i <= num;++i) {
		if (n % i == 0)
			return false;
	}
	return true;
} 
int l = 0;
int k = 0;
int main() {
	scanf("%d %d", &l, &k);
	string str;
	cin >> str;
	if (k > l) {
		printf("404");
		return 0;
	}
	for (int i = 0;i <= str.size() - k;++i) {
		string t = str.substr(i, k);
		int temp = stoi(t);
		if (IsPrime(temp)) {
			printf("%s", t.c_str());
			return 0;
		}
	}
	printf("404");
	return 0;
}
