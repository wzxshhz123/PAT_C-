#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;
vector<unordered_map<int, bool>> vec(205);
int main() {
	int nv = 0;
	int ne = 0;
	scanf("%d %d", &nv, &ne);
	for (int i = 0;i < ne;++i) {
		int a = 0;
		int b = 0;
		scanf("%d %d", &a, &b);
		vec[a][b] = true;
		vec[b][a] = true;
	}
	int k = 0;
	scanf("%d", &k);
	for (int i = 0;i < k;++i) {
		int size = 0;
		scanf("%d", &size);
		unordered_set<int> s;
		for (int j = 0;j < size;++j) {
			int e = 0;
			scanf("%d", &e);
			s.insert(e);
		}
		int flag = 1;
		auto res = vec;
		for (auto iter = s.begin();iter != s.end();++iter) {
			auto temp = iter;
			auto be = ++iter;
			iter = temp;
			for (auto iter_2 = be;iter_2 != s.end();++iter_2) {
				if (vec[*iter].count(*iter_2) == 0) {
					flag = 0;
					break; 
				}
				else {
					vec[*iter][*iter_2] = false;
				}
			}
			if (!flag)
				break;
		}
		int f = 1;
		if (flag) {
			auto st = *s.begin();
			for (auto miter = vec[st].begin();miter != vec[st].end();++miter) {
				int x = 0;
				int v = miter->first;
				if (miter->second == true) {
					for (auto iter = ++s.begin();iter != s.end();++iter) {
						if (vec[*iter][v] == false) {
							x = 1;
							break;
						}
					}
					f = x;
				}
			}
		if (f)
			printf("Yes\n");
		else
			printf("Not Maximal\n");
		}
		else
			printf("Not a Clique\n");
		vec = move(res);
	}
}
