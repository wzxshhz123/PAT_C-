#include <iostream>
using namespace std;
struct date {
	string name;
  int year;
  int month;
  int day;
  
  date() {
	}
  date(int y, int m, int d) : year(y), month(m), day(d) {
	}
	date(date& rhs) {
		name = rhs.name;
		year = rhs.year;
		month = rhs.month;
		day = rhs.day;
	}

  bool operator<(const date& rhs) {
  	if (year < rhs.year) {
  		return false;
		}
		if (year == rhs.year && month < rhs.month) {
			return false;
		}
		if (year == rhs.year && month == rhs.month && day < rhs.day) {
			return false;
		}
		return true;
	}
	bool operator>(const date& rhs) {
		return !operator<(rhs);
	}
	bool IsTrue() {
    if (year > 2014 || ((year == 2014) && (month > 9)) || ((year == 2014) && (month == 9) && (day > 6))) {
			return false;
		}
		if (year < 1814 || ((year == 1814) && (month < 9)) || ((year == 1814) && (month == 9) && (day < 6))) {
			return false;
		}
		return true;
	}
};
int main() {
	int n = 0;
	date max(2014, 9, 7);
	date min(1814, 9, 5);
	int num = 0;
	scanf("%d",&n);
	while(n--) {
    string name;
   	date now;
		cin >> name;
		scanf("%d/%d/%d",&now.year,&now.month,&now.day);
		if(now.IsTrue()) {
			now.name = name;
			++num;
			if (now > max) {
				max.name = now.name;
				max.year = now.year;
				max.month = now.month;
				max.day = now.day;
			}
			if (now < min) {
		    min.name = now.name;
				min.year = now.year;
				min.month = now.month;
				min.day = now.day;
			}
		}
	}
	
	num != 0? printf("%d %s %s",num,max.name.c_str(),min.name.c_str()) : printf("0");
  return 0;
}
