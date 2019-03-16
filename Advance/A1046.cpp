#include <cstdio>
#include <vector>
#include <algorithm>
#include <iterator>
#include <numeric>
using namespace std;
int main() {
	int num = 0;
	int sum = 0;
	scanf("%d",&num);
	int n = num;
	vector<int>vec;
	vector<int>dist;
	dist.push_back(0);
	while(num--) {
		int e = 0;
		scanf("%d",&e);
		vec.push_back(e);
		sum += e;
		dist.push_back(sum);
	}
	int t = 0;
	scanf("%d",&t);
	if (!t) {
		return 0;
	}
	while(t--) {
		int a = 0;
		int b = 0;
		scanf("%d %d",&a,&b);
		--a;
		--b;
		int sum_1 = 0;
		int sum_2 = 0;
		if (a == b) {
			t == 0? printf("0") : printf("0\n");
		}
		else {
			if (a > b) 
				 swap(a,b);
				sum_1 = dist[b] - dist[a];
				sum_2 = sum - sum_1;
		}
		t == 0? printf("%d",min(sum_1,sum_2)) : printf("%d\n",min(sum_1,sum_2));
	}
	return 0;
}
