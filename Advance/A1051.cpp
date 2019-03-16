#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;
int main() {
	int m = 0;
	int n = 0;
	int k = 0;
	scanf("%d %d %d", &m, &n, &k);
	while (k--) {
		stack<int> s;
//		vector<int> vec;
		deque<int> d;
		for (int i = 0;i < n;++i) {
			int e = 0;
			scanf("%d", &e);
//			vec.push_back(e);
			d.push_back(e);
		}
		int i = 1;
		while (i <= n && s.size() < m && !d.empty()) {
			s.push(i);
			while (!s.empty() && !d.empty()) {
				if (s.top() == d.front()) {
					s.pop();
					d.pop_front();
				}
				else
					break;
			}
			++i; 
		}
		if (s.empty()) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
	}
	return 0;
} 
