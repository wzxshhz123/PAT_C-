#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;
int main() {
	map<int,int>s;
	int num = 0;
	scanf("%d",&num);
	while (num--) {
		int index = 0;
		int scroe = 0;
		scanf("%d %d",&index,&scroe);
		s[index] += scroe;
	}
	int max = -1;
	int i = -1;
	for(auto iter = s.cbegin();iter != s.cend();++iter) {
		if (iter->second > max) {
			max = iter->second;
			i = iter->first;
		}
	}
	printf("%d %d",i,max);
} 
