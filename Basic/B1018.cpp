#include <cstdio>
#include <algorithm>
#include <iterator>
using namespace std;
inline int max(int *a) {
	return max(max(a[0],a[1]),a[2]);
}
int main() {
	int n = 0;
	int a_win = 0;
	int b_win = 0;
	int ping = 0;
	int a_s[3] = {0};
	int b_s[3] = {0};
	scanf("%d",&n);
	while (n--) {
		char a;
		char b;
		getchar();
		scanf("%c %c",&a,&b);
		if (a == b) {
			++ping;
			continue;
		}
		if (a == 'C' && b == 'J') {
			++a_win;
			++a_s[0];
		}
		else if(a == 'C' && b == 'B') {
			++b_win;
			++b_s[2];
		}
		else if(a == 'J' && b == 'C') {
			++b_win;
			++b_s[0];
		}
		else if(a == 'J' && b == 'B') {
			++a_win;
			++a_s[1];
		}
		else if(a == 'B' && b == 'C') {
			++a_win;
			++a_s[2];
		}
		else if(a == 'B' && b == 'J') {
			++b_win;
			++b_s[1];
		}
	}
	printf("%d %d %d\n",a_win,ping,b_win);
	printf("%d %d %d\n",b_win,ping,a_win);
	int a_max = max(a_s);
	int b_max = max(b_s);
	if (a_s[2] == a_max) {
		printf("B ");
	}
	else if(a_s[0] == a_max) {
		printf("C ");
	}
	else {
		printf("J ");
	}
	if (b_s[2] == b_max) {
		printf("B");
	}
	else if(b_s[0] == b_max) {
		printf("C");
	}
	else {
		printf("J");
	}
	return 0;
}
