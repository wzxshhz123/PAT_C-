#include <iostream>
#include <cmath>
#include <climits>
using namespace std;
int main() {
	int n = 0;
	scanf("%d", &n);
	int max = -1;
	string max_id;
	int min = INT_MAX;
	string min_id;
	for (int i = 0;i < n;++i) {
		string id;
		cin >> id;
		int x = 0;
		int y = 0;
		scanf("%d %d", &x, &y);
		int res = abs(x * x) + abs(y * y);
		if (res > max) {
			max = res;
			max_id = id;
		}
		if (res < min) {
			min = res;
			min_id = id;
		}
	}
	cout << min_id << " " << max_id;
	return 0; 
}
