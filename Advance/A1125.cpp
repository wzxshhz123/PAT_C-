#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
int main() {
	int n = 0;
	scanf("%d", &n);
	vector<int> vec;
	for (int i = 0;i < n;++i) {
		int e = 0;
		scanf("%d", &e);
		vec.push_back(e);
	}
	sort(vec.begin(), vec.end());
	double st = vec.front();
	for (int i = 1;i < vec.size();++i) {
		st += vec[i];
		st /= 2;
	}
	cout << floor(st);
} 
