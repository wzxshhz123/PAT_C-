#include <iostream>
#include <string>
#include <cassert>
using namespace std;
int main() {
	int n = 0;
	scanf("%d", &n);
	for (int i = 0;i < n;++i) {
		string str;
		cin >> str;
		int middle = str.length() / 2;
		auto pre = str.substr(0, middle);
		auto back = str.substr(middle, middle);
		unsigned long long product = stoull(pre) * stoull(back);
		unsigned long long res = stoull(str);
		if (product == 0 || res % product != 0)
			printf("No\n"); 
		else
			printf("Yes\n");
	}
	return 0;
}

