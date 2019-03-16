#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
constexpr int maxn = 1001; 
int n = 0;
int index = 0;
vector<int>num;
vector<int>CBT(maxn);
void Inorder(int root) {
	if (root > n)
		return ;
	Inorder(root * 2);
//	CBT.push_back(num[index]);
	if (index == 4)
		printf("");
	CBT[root] = num[index];
	++index;
	Inorder(root * 2 + 1);
}
int main() {
	scanf("%d", &n);
	for (int i = 0;i < n;++i) {
		int e = 0;
		scanf("%d", &e);
		num.push_back(e);
	}
	sort(num.begin(), num.end());
	Inorder(1);
	int flag = 0;
	for (int i = 1;i <= n;++i) {
		if (flag)
			printf(" ");
		flag = 1;
		printf("%d", CBT[i]);
	}
	return 0; 
}
