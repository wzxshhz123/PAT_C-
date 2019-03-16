#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
vector<int>sequ;
vector<int>temp;
vector<int>res;
int max_sum = -1;	
int n = 0;
int p = 0;
int k = 0;
void Pre() {
	int temp = 0;
	int x = 0;
	do {
		x = pow(temp, p);
		if (x < n)
			sequ.push_back(x);
		++temp;
	} while(x < n);
//	for (auto item : sequ) {
//		cout << item << " ";
//	}
}
void DFS(int index, int now, int sum, int frac_sum) {
	if (sum == n && now == k) {
		if (frac_sum > max_sum) {
			res = temp;
			max_sum = frac_sum;
		}
		return ;
	}
	if (sum > n || now > k) {
		return ;
	}
	if (index >= 1) {
		temp.push_back(index);
//		x.push_back(index);
		DFS(index, now + 1, sum + sequ[index], frac_sum + index);
		temp.pop_back();
//		x.pop_back();
		DFS(index - 1, now, sum, frac_sum);
	}	
}
int main() {
	scanf("%d %d %d", &n, &k, &p);
	if (n == 1) {
		printf("1 = 1^%d", p);
		for (int i = 1;i < k;++i) {
			printf(" + 1^%d", p);
		}
		return 0;
	}
	Pre();
	DFS(sequ.size() -  1, 0, 0, 0);
	if (max_sum == -1) {
		printf("Impossible");
	}
	else {
		printf("%d = ", n);
		int flag = 0;
		for (auto item : res) {
			if (flag) 
				printf(" + ");
			flag = 1;
			printf("%d^%d", item, p);
		}
	}
	return 0;
} 
