#include <iostream>
using namespace std;
class Time {
 public:
  int hour;
  int min;
  int sec;
  
  Time() {
	}
 
  Time(int y, int m, int d) : hour(y), min(m), sec(d) {
	}
	
	Time(Time& rhs) {
		hour = rhs.hour;
		min = rhs.min;
		sec = rhs.sec;
	}

  bool operator<(const Time& rhs) {
  	if (hour < rhs.hour) {
  		return true;
		}
		if (hour == rhs.hour && min < rhs.min) {
			return true;
		}
		if (hour == rhs.hour && min == rhs.min && sec < rhs.sec) {
			return true;
		}
		return false;
	}
	bool operator>(const Time& rhs) {
		return !operator<(rhs);
	}
};
int main() {
	int n = 0;
	Time out_max(0, 0, 0);
	Time in_min(25, 0, 0);
	string out_max_name;
	string in_min_name;
	scanf("%d",&n);
	while(n--) {
    string name;
		cin >> name;
		Time out;
		Time in;
		scanf("%d:%d:%d",&in.hour,&in.min,&in.sec);
		scanf("%d:%d:%d",&out.hour,&out.min,&out.sec);
			if (out > out_max) {
				out_max_name = name;
				out_max.hour = out.hour;
				out_max.min = out.min;
				out_max.sec = out.sec;
			}
			if (in < in_min) {
				in_min_name = name;
				in_min.hour = in.hour;
				in_min.min = in.min;
				in_min.sec = in.sec;
			}
		}
	printf("%s %s",in_min_name.c_str(),out_max_name.c_str());
  return 0;
}
