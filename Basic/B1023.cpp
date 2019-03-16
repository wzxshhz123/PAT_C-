#include <iostream>
#include <algorithm>
#include <list>
using namespace std;
int main()  {
	int n = 10;
	list<int>l;
	for (int i = 0;i < n;++i) {
		int e = 0;
		scanf("%d", &e);
		for (int j = 0;j < e;++j)
			l.push_back(i);
	}
	l.sort();
	for (auto iter = l.begin();iter != l.end();++iter) {
		if (*iter != 0) {
			printf("%d", *iter);
			l.erase(iter);
			break;
		}
	}
	for (auto item : l) {
		cout << item;
	}
	return 0;
}
