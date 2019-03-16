#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;
struct Node {
	int data = -1;
	vector<int>child;	
};
int n = 0;
double p = 0;
double r = 0;
int min_depth = INT_MAX;
int num = 1;
vector<Node>vec;
void DFS(int index, int depth) {
	if (vec[index].child.size() == 0) {
		if (depth < min_depth) {
			min_depth = depth;
			num = 1;
		}
		else if (depth == min_depth)
			++num;
		return ;
	}
	else {
		for (int i = 0;i < vec[index].child.size();++i)
			DFS(vec[index].child[i], depth + 1);
	}
}
void Order(int index) {
	printf("%d ", vec[index].data);
	if (vec[index].child.size() != 0)
		for (int i = 0;i < vec[index].child.size();++i)
			Order(vec[index].child[i]);			
}
int main() {
	scanf("%d %lf %lf", &n, &p, &r);
	r /= 100;
	for (int i = 0;i < n;++i) {
		Node ins;
		ins.data = i;
		int size = 0;
		scanf("%d", &size);
		if (size != 0)
			for (int j = 0;j < size;++j) {
				int e = 0;
				scanf("%d", &e);
				ins.child.push_back(e);
			}
		vec.push_back(ins);
	}
//	for (auto item : vec) {
//		cout << item.data << " ";
//	}
//	Order(0);
	DFS(0, 0);
	printf("%.4f %d", p * pow(1 + r, min_depth), num);
	return 0;
}
 
