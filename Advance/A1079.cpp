#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int n = 0;
double p = 0;
double r = 0;
struct Node {
	double data;
	vector<int>child;
}; 
double res = 0;
vector<Node>vec;

void DFS(int index, int depth) {
	if (vec[index].child.size() == 0) {
		res += vec[index].data * pow(1 + r, depth);
		return ;
	}
	else {
		for (int i = 0;i < vec[index].child.size();++i)
			DFS(vec[index].child[i], depth + 1);
	}
}
int main() {
	scanf("%d %lf %lf", &n, &p, &r);
	r /= 100;
	for (int i = 0;i < n;++i) {
		Node ins;
		int size = 0;
		scanf("%d", &size);
		if (size == 0) {
			double e = 0;
			scanf("%lf", &e);
			ins.data = e;
		}
		else
			for (int j = 0;j < size;++j) {
				int e = 0;
				scanf("%d", &e);
				ins.child.push_back(e);
			}
		vec.push_back(ins);
	}
	DFS(0, 0);
	printf("%.1f", p * res);
	return 0;
}
