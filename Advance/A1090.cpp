#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int n = 0;
double p = 0;
double r = 0;
struct Node {
	int data = -1;
	vector<int>child;
}; 
double res = 0;
int max_depth = -1;
int num = 1;
vector<Node>vec(100005);

void DFS(int index, int depth) {
	if (vec[index].child.size() == 0) {
		if (depth > max_depth) {
			max_depth = depth;
			num = 1;
		}
		else if (depth == max_depth) {
			++num;
		}
		return ;
	}
	else {
		for (int i = 0;i < vec[index].child.size();++i)
			DFS(vec[index].child[i], depth + 1);
	}
}
void Preorder(int index) {
	if (vec[index].data == -1)  return ;
	Node root = vec[index];
	printf("%d ", vec[index].data);
	if (vec[index].child.size() != 0)
		for (int i = 0;i < vec[index].child.size();++i)
			Preorder(vec[index].child[i]);
}
int main() { 
	scanf("%d %lf %lf", &n, &p, &r);
	r /= 100;
	int root = -2;
	for (int i = 0;i < n;++i) {
		int father = 0;
		vec[i].data = i;
		scanf("%d", &father);
		if (father == -1) {
			root = i;
		}
		else {
			vec[father].child.push_back(i);
		}
	}
	DFS(root, 0);
	printf("%.2f %d\n", p * pow(1 + r, max_depth), num);
	return 0;
}
