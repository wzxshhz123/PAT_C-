#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
	int n = 0;
	scanf("%d", &n);
	vector<string> vec;
//	getchar();
	while (n--) {
		string str;
		cin >> str;
//		getline(cin, str);
		vec.push_back(str);
	}
	int flag = 0;
	for (int i = 0;i < vec.size();++i) {
		auto str = vec[i];
		int f = 0;
		int other = 0;
		int x = 0;
		int y = 0;
		int z = 0;
		bool p = false;
		bool t = false;
		int num_p = 0;
		int num_t = 0;
		for (int j = 0;j < str.length();++j) {
			if (str[j] == 'P') {
				++num_p;
			}
			else if (str[j] == 'T') {
				++num_t;
			}
			if (str[j] != 'P' && str[j] != 'T' && str[j] != 'A' && str[j] != ' ')
				++other;
			if (str[j] == 'A') {
				if (num_p == 0 && num_t == 0)
					++x;
				else if (num_p == 1 && num_t == 0)
					++y;
				else if (num_p == 1 && num_t == 1)
					++z;
			}
		}
		if (flag)
			printf("\n");
		flag = 1;
		if (other != 0 || num_p != 1 || num_t != 1 || y == 0) {
			printf("NO");
			continue;
		}
		if (z - (y - 1) * x == x)
			printf("YES");
		else 
			printf("NO");
	}
	return 0;
}
