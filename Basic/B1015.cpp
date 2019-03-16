#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Stu {
	long long id;
	int d;
	int c;
};
bool cmp(const Stu &a, const Stu &b) {
	int sum_1 = a.d + a.c;
	int sum_2 = b.d + b.c;
	if (sum_1 != sum_2) {
		return sum_1 > sum_2;
	}
	else if (a.d != b.d) {
		return a.d > b.d;
	}
	else {
		return a.id < b.id;
	}
}
int main() {
	int n = 0;
	int l = 0;
	int h = 0;
	scanf("%d %d %d",&n,&l,&h);
	vector<Stu>first;
	vector<Stu>second;
	vector<Stu>third;
	vector<Stu>fouth;
	int sum = 0;
	while (n--) {
		Stu instance;
		int d = 0;
		int c = 0;
		long long id = 0;
//		cin >> id >> d >> c;
		scanf("%lld %d %d",&id,&d,&c);
		instance.id = id;
		instance.d = d;
		instance.c = c;
		if (d >= l && c >= l) {
				++sum;
				if (d >= h && c >= h) {
				first.push_back(instance);
			}
		else if (d >= h && c < h) {
				second.push_back(instance);
			}
		else if (d < h && c < h && d >= c) {
				third.push_back(instance);
			} 
		else if (d >= l && c >= l) {
				fouth.push_back(instance);
			}
		}
	
	}
	sort(first.begin(),first.end(),cmp);
	sort(second.begin(),second.end(),cmp);
	sort(third.begin(),third.end(),cmp);
	sort(fouth.begin(),fouth.end(),cmp);
	cout << sum;
	for (auto iter = first.begin();iter != first.end();++iter) {
//		cout << endl << iter->id << " " << iter->d << " " << iter->c;
		printf("\n%lld %d %d",iter->id,iter->d,iter->c);
	}
	for (auto iter = second.begin();iter != second.end();++iter) {
//		cout << endl << iter->id << " " << iter->d << " " << iter->c;
				printf("\n%lld %d %d",iter->id,iter->d,iter->c);

	}
	for (auto iter = third.begin();iter != third.end();++iter) {
//		cout << endl << iter->id << " " << iter->d << " " << iter->c;
				printf("\n%lld %d %d",iter->id,iter->d,iter->c);

	}
	for (auto iter = fouth.begin();iter != fouth.end();++iter) {
//		cout << endl << iter->id << " " << iter->d << " " << iter->c;
				printf("\n%lld %d %d",iter->id,iter->d,iter->c);

	}
	return 0;
}
