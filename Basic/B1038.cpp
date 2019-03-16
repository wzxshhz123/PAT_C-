#include <iostream>
#include <unordered_map>
using namespace std;
int main() {
	unordered_map<int, int> m;
	int n = 0;
	scanf("%d", &n);
	while (n--) {
		int e = 0;
		scanf("%d", &e);
		++m[e];
	}
	int k = 0;
	scanf("%d", &k);
	int flag = 0;
	while (k--) {
		int query = 0;
		scanf("%d", &query);
		if (flag)
			printf(" ");
		flag = 1;
		if (m.count(query)) {
			printf("%d",m[query]);
		}
		else
			printf("0");
	}
	return 0;
} 
