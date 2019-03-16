#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
map<char, string>m {
	{'A',"MON"},
	{'B',"TUE"},
	{'C',"WED"},
	{'D',"THU"},
	{'E',"FRI"},
	{'F',"SAT"},
	{'G',"SUN"}
};
int main() {
	vector<string>vec_str;
	int n = 4;
	int s[3];
	while (n--) {
		string s;
		cin >> s;
		vec_str.push_back(s);
	}
	int k = 0;
	int j = 0;
	for(int i = 0;i < vec_str[0].size() && i < vec_str[1].size();++i) {
		if (vec_str[0][i] == vec_str[1][i] && vec_str[0][i] >= 'A' && vec_str[0][i] <= 'G') {
//			s[k++] = m[vec_str[0][i]].c_str();
			cout << m[vec_str[0][i]];
			j = i + 1;
			break;
		}
	}
	for (int i = j;i < vec_str[0].size() && i < vec_str[1].size();++i) {
		if (vec_str[0][i] == vec_str[1][i] && vec_str[0][i] >= 'A' && vec_str[0][i] <= 'N') {
			int minus = vec_str[0][i] - 'A' + 10;
			s[k++] = minus;
			break;
		}
		else if (vec_str[0][i] == vec_str[1][i] && isdigit(vec_str[0][i])) {
			s[k++] = vec_str[0][i] - '0';
			break;
		}
	}
	for(int i = 0;i < vec_str[2].size() && i < vec_str[3].size();++i) {
		if (vec_str[2][i] == vec_str[3][i] && isalpha(vec_str[2][i])) {
			s[k++] = i;
			break;
		}
	}
	printf(" %02d:%02d",s[0],s[1]);
}
