#include <cstdio>
#include <vector>
using namespace std;
float res[2005] = {0};
float temp[1005] = {0};
int main() {
	int n = 2;
	int t = 0;
	int max = 0;
	int num = 0;
	vector<int> vec;
	while (n--) {
		scanf("%d",&t);
		while(t--) {
			int e = 0;
			float coe = 0;
			scanf("%d %f",&e,&coe);
			if(n == 1) {
				vec.push_back(e);
				temp[e] = coe;
			}
			else {
				for(const auto &item : vec) {
					res[item + e] += coe * temp[item]; 
					item + e > max ? max = item + e : printf("");
				}
			}
		}
	}
	for(int i = 0;i < 2005;++i) {
		if(res[i]) {
			++num;
		}
	} 
	printf("%d",num);
	for(int i = max;i >= 0;--i) {
		if (res[i]) {
			printf(" %d %.1f",i,res[i]);
		}
	}
	return 0;
}
