#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
struct Mouse {
	int rank = 0;
	int weight = 0;
};
int main() {
	int p = 0;
	int g = 0;
	scanf("%d %d", &p, &g);
	vector<Mouse>vec;
	for (int i = 0;i < p;++i) {
		int e = 0;
		scanf("%d", &e);
		Mouse in;
		in.weight = e;
		vec.push_back(in);
	}
	queue<int> q;
	for (int i = 0;i < p;++i) {
		int e = 0;
		scanf("%d", &e);
		q.push(e);
	}
//	while (!q.empty()) {
//		cout << q.front() << " ";
//		q.pop(); 
//	}
	int temp = p;
	int group = 0;
	while (q.size() != 1) {
		if (temp % g == 0) {
			group = temp / g;
		}
		else {
			group = temp / g + 1;
		}
		for (int i = 0;i < group;++i) {
			int k = q.front();
			for (int j = 0;j < g;++j) {
				if (i * g + j >= temp)
					break;
				int front = q.front();
				if (vec[front].weight > vec[k].weight) {
					k = front;
				}
				vec[front].rank = group + 1;
				q.pop();
			}
			q.push(k);
		}
		temp = group;
	}
	vec[q.front()].rank = 1;
	int flag = 0;
	for (auto item : vec) {
		if (flag)
			printf(" ");
		flag = 1;
		printf("%d", item.rank);
	}
	return 0;
}
