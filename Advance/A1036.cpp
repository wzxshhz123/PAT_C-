#include <iostream>
#include <utility>
using namespace std;
const string boy = "M";
const string girl = "F";
int main() {
	int n = 0;
	scanf("%d",&n);
	pair<string, string> male;
	pair<string, string> female;
	int max = -1;
	int min = 101;
	while (n--) {
		string name;
		string gender;
		string id;
		int grade = 0;
		cin >> name >> gender >> id >> grade;
		if (gender == "F" && grade > max) {
				max = grade;
				female = make_pair(name, id);
		}
		else if (gender == "M" && grade < min) {
				min = grade;
				male = make_pair(name, id);
		}
	}
	if (min == 101) {
		cout << female.first << " " << female.second << endl;
		cout << "Absent" << endl;
		cout << "NA";
	}
	else if (max == -1) {
		cout << "Absent" << endl;
		cout << male.first << " " << male.second << endl;
		cout << "NA";
	}
	else {
		cout << female.first << " " << female.second << endl;
		cout << male.first << " " << male.second << endl;
		cout << max - min;
	}
	return 0; 
}

