#include <cstdio>
#include <deque>
using namespace std;
int main() {
	int n = 0;
	int b = 0;
	deque<int>s;
	scanf("%d %d",&n,&b);
	do {
		s.push_front(n % b);
		n /= b;
	}while(n);
	
	int flag = 1;
	auto iter1 = s.cbegin();
  auto iter2 = s.crbegin();
	for (;iter1 != s.cend() || iter2 != s.crend();++iter1,++iter2) {
		if (*iter1 != *iter2) {
			flag = 0;
			break;
		}
	}
	flag == 1? printf("Yes\n") : printf("No\n");
	int i = 0;
	for(const auto &item : s) {
		if (i) printf(" ");
		printf("%d",item);
		i = 1;
	}
	return 0;
}
