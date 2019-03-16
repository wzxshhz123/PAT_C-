#include <string>
#include <iostream>
#include <unordered_map>
#include <stack>
using namespace std;
string hash_1[] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
string hash_2[] = {"0","tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
unordered_map<string,int>hash_3 = {
	{"tret", 0},
	{"jan", 1},
	{"feb", 2},
	{"mar", 3},
	{"apr", 4},
	{"may", 5},
	{"jun", 6},
	{"jly", 7},
	{"aug", 8},
	{"sep", 9},
	{"oct", 10},
	{"nov", 11},
	{"dec", 12}
};
unordered_map<string, int>hash_4 = {
	{"tam", 1},
	{"hel", 2},
	{"maa", 3},
	{"huh", 4},
	{"tou", 5},
	{"kes", 6},
	{"hei", 7},
	{"elo", 8},
	{"syy", 9},
	{"lok", 10},
	{"mer", 11},
	{"jou", 12}
};
int main() {
	int n = 0;
	scanf("%d", &n);
	getchar();
	int f = 0;
	while (n--) {
		string str;
		getline(cin, str);
		if (f)
			printf("\n");
		f = 1;
		if (isdigit(*str.begin())) {
			stack<string>res;
			int num = stoi(str);
			int x = num % 13;
			num /= 13;
			if (num != 0 && x == 0) {
				
			}
			else
				res.push(hash_1[x]);
			if (num != 0) {
				int x = num % 13;
				if (x != 0)
				res.push(hash_2[x]);
			}
			int flag = 0;			
			while (!res.empty()) {
				if (flag)
					printf(" ");
				flag = 1;
				cout << res.top();
				res.pop(); 
			}
		}
		else {
			if (str.find(' ') != string::npos) {
				int pos = str.find(' ');
				auto a = str.substr(0, pos);
				auto b = str.substr(pos + 1, str.length());
//				cout << a << " " << b;
				int sum = hash_4[a] * 13 + hash_3[b];
				printf("%d", sum);
			}
			else {
				int sum = 0;
				if (hash_3.count(str) != 0)
					sum = hash_3[str];
				else
					sum = hash_4[str] * 13;
				printf("%d", sum);
			}
		}
	}
	return 0;
}
