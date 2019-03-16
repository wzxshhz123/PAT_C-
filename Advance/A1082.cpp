#include <iostream>
#include <string>
#include <stack>
char *a[] = {"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
char *b[] = {"Shi","Bai","Qian","Wan","Yi"};
using namespace std;
int main() {
	//  输入 
	string str;
	stack<char*>s;
	cin >> str;
	if (str[0] == '-') {
		cout << "Fu ";
		str.erase(str.begin());
	}
	
	//  处理为 0 时的情况 
	int r = stoi(str);
	if (!r) {
		cout << "ling";
		return 0;
	}
	
	int i = 0;
	int j = 0;
	for (auto iter = str.rbegin();iter != str.rend();++iter) {
		int index = *iter - '0';
		if (index != 0) {
			switch(i) {
				case 1:
					s.push(b[0]);
					break;
				case 2:
					s.push(b[1]);
					break;
				case 3:
					s.push(b[2]);
					break;
				default:
					break;
			}
		}
		++i;
		if (i == 4) {
			i = 0;
		} 
		switch (j) {
			case 4: {
				auto temp = iter;
				int x = 0;
				int flag = 0;
				while (temp != str.rend() && x != 4) {
					if (*temp - '0' != 0){
						flag = 1;
						break;
					}
					++temp;
					++x;
				}
				if (flag)
					s.push(b[3]);
				break;
			}
			case 8:
				s.push(b[4]);
				break;
			default:
				break;
		}
		++j;
		
		if (!index) {
				if (*(iter - 1) - '0' != 0 && i != 1) {
					s.push(a[index]);
				}
		}
		else {
			s.push(a[index]);
		}
	}
	
	// 输出 
	int flag = 0;
	while (!s.empty()) {
		if (flag)  cout << " ";
		cout << s.top();
		s.pop();
		flag = 1;
	}
	return 0;
}
