#include <stack>
#include <cstdio>
using namespace std;
int main() {
	int rgb[3] = {0};
	scanf("%d %d %d",&rgb[0],&rgb[1],&rgb[2]);
	int i = 3;
	stack<stack<int>> m;
	while (i--) {
	  stack<int> s;
	  int temp = -1;
	  int j = 0;
  	do {
  		temp = rgb[i] % 13;
  		s.push(temp);
  		rgb[i] /= 13;
  		++j;
    } while(rgb[i]);
    if (j != 2) 
			 s.push(0);
    m.push(s); 
	}
	printf("#"); 
	while(!m.empty()) {
		auto s = m.top();
		while(!s.empty()) {
			switch(s.top()) {
				case 10:
					printf("A");
					break;
				case 11:
					printf("B");
					break;
				case 12:
					printf("C");
					break;
				default:
					printf("%d",s.top()); 
			}
			s.pop();
		}
		m.pop();
	}
	return 0;
}
