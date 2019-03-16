#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int main() {
	int k = 0;
	scanf("%d", &k);
	while(k--) {
		int n = 0;
		scanf("%d", &n);
		vector<int>vec;
		vec.push_back(-1);
		unordered_map<int, bool> mp;
		int flag = 1;
		for (int i = 0;i < n;++i) {
			int e = 0;
			scanf("%d", &e);
			if (mp.count(e) != 0)
				flag = 0;
			else {
				vec.push_back(e);
				mp[e] = true;
			}
		}
		if (!flag) {
			printf("NO\n");
			continue;
		}
		for (int i = 1;i <= n;++i) {
			for (int j = i + 1;j <= n;++j) {
				if (abs(vec[i] - vec[j]) == abs(i - j)) {
					flag = 0;
					break;
				}
			}
		}
		if (!flag)
			printf("NO\n");
		else
			printf("YES\n"); 
	}
} 
