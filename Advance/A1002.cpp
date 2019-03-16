#include <cstdio>
using namespace std;
float res[1005] = {0};
int main() {
	int n = 2;
	int t = 0;
	int max = 0;
	int num = 0;
	while (n--) {
		scanf("%d",&t);
		while(t--) {
			int e = 0;
			float coe = 0;
			scanf("%d %f",&e,&coe);
			if (!res[e]) {
				++num;
			} 
			res[e] += coe;
			if (!res[e]) {
				--num;
			}
			e > max ? max = e : printf("");
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
