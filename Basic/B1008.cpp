#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
	int n = 0;
	int m = 0;
	scanf("%d %d",&n,&m);
	m = m % n;
	vector<int>vec;
	while(n--) {
		int e = 0;
		scanf("%d",&e);
		vec.push_back(e);
	}
	reverse(vec.begin(),vec.end());
	reverse(vec.begin(),vec.begin() + m);
	reverse(vec.begin() + m ,vec.end());
	int i = 0;
	for(const auto &item : vec) {
		i == 0? printf("%d",item) : printf(" %d",item);
		i = 1;
	}
	return 0;
}
