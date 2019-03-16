#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<int>cents;
double t[1005] = {0};
int j = 0;
struct Record {
	string id;
	int month;
	int day;
	int hour;
	int minute;
	int staus;
	
	friend std::ostream &operator<<(std::ostream &os, const Record &rhs) {
		os << "id: " << rhs.id << " " << rhs.month << ":" << rhs.day << ":" << rhs.hour << ":" << rhs.minute << ":" << rhs.staus;
		return os;
	}
};
bool Cmp(const Record &a, const Record &b) {
	if (a.id != b.id)
		return a.id < b.id;
	else if (a.month != b.month)
		return a.month < b.month;
	else if (a.day != b.day) 
		return a.day < b.day;
	else if (a.hour != b.hour)
		return a.hour < b.hour;
	else if (a.minute != b.minute)
		return a.minute < b.minute;
	else 
		return a.staus > b.staus;
}
void Pro(Record &lhs, Record &rhs) {
	double total = 0;
	int sum = 0;
	auto temp = lhs;
	while (true) {
		if (lhs.day == rhs.day && lhs.hour == rhs.hour && lhs.minute == rhs.minute)
			break;
		++lhs.minute;
		++sum;
		total += cents[lhs.hour];
		
		if (lhs.minute == 60) {
			++lhs.hour;
			lhs.minute = 0;
		}
		if (lhs.hour == 24) {
			++lhs.day;
			lhs.hour = 0;
		}
	}
	printf("\n%02d:%02d:%02d %02d:%02d:%02d %d $%.2lf",temp.day,temp.hour,temp.minute,rhs.day,rhs.hour,rhs.minute,sum,total / 100);
	t[j] += total / 100;
}
int main() {
	int n = 24;
	while (n--) {
		int e = 0;
		scanf("%d",&e);
		cents.push_back(e);
	}
	vector<Record>vec;
	scanf("%d",&n);
	while (n--) {
		Record instance;
		string id;
		string staus;
		int month = 0;
		int day = 0;
		int hour = 0;
		int minute = 0;
		cin >> id;
		scanf("%d:%d:%d:%d",&month,&day,&hour,&minute);
		instance.id = id;
		instance.month = month;
		instance.day = day;
		instance.hour = hour;
		instance.minute = minute;
		cin >> staus;
		if (staus == "on-line") {
			instance.staus = 1;
		}
		else
			instance.staus = 0;
		vec.push_back(instance);
	}
	sort(vec.begin(), vec.end(), Cmp);
//	for (auto item : vec) {
//		cout << item << endl;
//	}
	auto temp = vec[0];
	int flag = 0;
	int p = 0;
	for (int i = 1;i < vec.size();++i) {
		if (temp.id == vec[i].id && temp.staus == 1 && vec[i].staus == 0) {
				if (!p){
					if (flag)  printf("\n");	
					printf("%s %02d",temp.id.c_str(),temp.month);
					p = 1;
				}
				flag = 1;
				Pro(temp,vec[i]);
		}
		if ((temp.id != vec[i].id || i == vec.size() - 1) && p){
			p = 0;
			printf("\nTotal amount: $%.2lf",t[j]);
			++j;
		}
		temp = vec[i];
	}
	return 0;
}
