#include <iostream>
#include <string>
#include <vector> 
#include <algorithm>
using namespace std;
struct Stu {
	string id;
	int grade;
	int local_rank;
	int local;
	int final_rank;
};
bool cmp(Stu &a, Stu &b) {
	if (a.grade != b.grade)
		return a.grade > b.grade;
	else 
		return a.id < b.id;
}
int main() {
	int n = 0;
	vector<Stu> vec;
	cin >> n;
	int sum = 0;
	int l_ts = 0;
	for (int i = 0;i < n;++i) {
		int t = 0;
		cin >> t;
		int ts = t;
		sum += t;
		while (t--) {
			Stu instance;
			string id;
			int grade;
			cin >> id >> grade;
			instance.id = id;
			instance.grade = grade;
			instance.local = i + 1;
			vec.push_back(instance);
		}
		sort(vec.begin() + l_ts, vec.begin() + ts + l_ts, cmp);
		auto iter = vec.begin() + l_ts;
		iter->local_rank = 1;
//			cout << iter->id << " " << iter->local_rank << endl;
		++iter;
//		cout << "l_ts: " << l_ts << " ts: " << ts << endl;
		for (int j = 1;iter != vec.begin() + ts + l_ts;++j,++iter) {
			if (iter->grade == (iter - 1)->grade) {
				iter->local_rank = (iter - 1)->local_rank;
			}
			else {
				iter->local_rank = j + 1;
			}
//			cout << iter->id << " " << iter->local_rank << endl;
		}
//		cout <<endl;
		l_ts += ts;
	}
	sort(vec.begin(), vec.end(), cmp);
	auto iter = vec.begin();
	cout << sum;
	int r = 1;
	for (int i = 0;iter != vec.end();++iter,++i) {
		if (i > 0 && iter->grade != (iter - 1)->grade) {
			r = i + 1;
		}
		cout << endl << iter->id << " " << r << " " << iter->local << " " << iter->local_rank;
	}
	return 0;
}
