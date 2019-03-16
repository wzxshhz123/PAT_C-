#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cstring>
#include <map>
using namespace std;
unordered_map<string, int>longest;
struct Record {
	string id;
	int status;
	int sum;
};
inline bool Cmp(const Record &lhs, const Record &rhs) {
	if (lhs.id != rhs.id)
		return lhs.id < rhs.id;
	else if (lhs.sum != rhs.sum)
		return lhs.sum < rhs.sum;
	else
		return lhs.status > rhs.status;
}
inline bool C(const Record &lhs, const Record &rhs) {
	return lhs.sum < rhs.sum;
}
int main () {
	int n = 0;
	int k = 0;
	scanf("%d %d", &n, &k);
	vector<Record>vec;
	vector<Record>p;
	while (n--) {
		Record e;
		int hour = 0;
		int minute = 0;
		int second = 0;
		char s[8];
		scanf("%s",&s);
		string id(s);
		scanf("%d:%d:%d", &hour, &minute, &second);
		char sta[4];
		scanf("%s",&sta);
		string status(sta);
		e.id = id;
		e.sum = hour * 3600 + minute * 60 + second;
		if (!strcmp(sta,"in")) {
			e.status = 1;
		} 
		else {
			e.status = 0;
		}
		vec.push_back(e);		
	}
	sort(vec.begin(), vec.end(), Cmp);
	int flag = 0;
	int max_time = -1;
	auto temp = vec[0];
	int i = 1;
	int size = vec.size();
	for (;i < size;++i) {
		if (temp.id == vec[i].id && temp.status == 1 && vec[i].status == 0) {
				longest[temp.id] += (vec[i].sum - temp.sum);
				max_time = max(max_time, longest[temp.id]);
				p.push_back(temp);
				p.push_back(vec[i]);
				if (i != size - 1) {
					temp = vec[i + 1];
					++i;
				}
					
		}
		else
			temp = vec[i]; 
	}
	
	sort(p.begin(), p.end(), C);
	int index = 0;
	int j = 0;
	int sum = 0;
	while (k--) {
		int hour = 0;
		int minute = 0;
		int second = 0;
		scanf("%d:%d:%d", &hour, &minute, &second);
		int time = hour * 3600 + minute * 60 + second;
		if (flag) 
			printf("\n");
		int size = p.size();
			while (j < size && p[j].sum <= time) {
				if (p[j].status == 1)
					++sum;
				else
					--sum; 
				++j;
			}
		flag = 1;
		printf("%d",sum);
	}
	
	printf("\n");
	int f = 0;
	map<string, int>m (move(longest.begin()), move(longest.end()));
	auto iter = m.begin();
	
	for (;iter != m.end();++iter) {
		if (iter->second == max_time) {
			if (f) 
				printf(" ");
			printf("%s", iter->first.c_str());
			f = 1;
		}
	}
	printf(" %02d:%02d:%02d", max_time / 3600, max_time % 3600 / 60, max_time % 60);

	return 0;
}
