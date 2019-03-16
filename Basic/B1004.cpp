#include <iostream>
using namespace std;
int main() {
	int n = 0;
	cin >> n;
	pair<string, string> res_max;
	pair<string, string> res_min;
	int max = -1;
	int min = 101;
	while (n--) {
		string name;
		string id;
		int grade = 0;
		cin >> name >> id >> grade;
		if (grade > max) {
			max = grade;
			res_max = make_pair(name, id);
		}
		if (grade < min) {
			min = grade;
			res_min = make_pair(name, id);
		}
	}
	cout << res_max.first << " " << res_max.second << endl;
	cout << res_min.first << " " << res_min.second;
}
