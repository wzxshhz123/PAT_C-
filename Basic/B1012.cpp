#include <cstdio>
#include <vector>
using namespace std;
int main() {
	int n = 0;
	scanf("%d",&n);
	vector<int>vec;
	while(n--) {
		int e = 0;
		scanf("%d",&e);
		vec.push_back(e);
	}
	int num[5] = {0};
	int count[5] = {0};
	int cal = 1;
	for (const auto& item : vec) {
		if(item % 5 == 0 && item % 2 == 0) {
			num[0] += item;
			++count[0];
			continue;
		}
		if(item % 5 == 1) {
			num[1] = num[1] + item * cal;
			cal *= -1;
			++count[1];
			continue;
		}
		if(item % 5 == 2) {
			++num[2];
			++count[2];
			continue;
		}
		if(item % 5 == 3) {
			num[3] += item;
			++count[3];
			continue;
		}
		if(item %5 == 4) {
			if (item > num[4]) {
				num[4] = item;
				++count[4];
			}
			continue;
		}
	}
	for(int i = 0;i < 5;++i) {
		if (count[i] == 0 && i == 0) {
			printf("N");
			continue;
		} 
		if (count[i] == 0 && i != 0) {
			printf(" N");
			continue;
		} 
		if(i == 0) {
			printf("%d",num[i]);
			continue;
		}
		if(i == 3) {
//			printf(" %d count:%d ",num[3],count);
			float avg = (float)num[3] / count[3];
			printf(" %.1f",avg);
			continue;
		}
		printf(" %d",num[i]);
	}
	return 0;
}
