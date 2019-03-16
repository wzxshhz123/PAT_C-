#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main() {
	int a = 0;
	int b = 0;
	scanf("%d %d", &a, &b);
	int res = a * b;
	string s = to_string(res);
	reverse(s.begin(), s.end());
	for (auto riter = s.find_first_not_of("0", 0) + s.begin();riter != s.end();++riter)
		printf("%c", *riter);
	return 0;	
}
