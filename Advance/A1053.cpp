#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
constexpr int maxn = 101;
int n = 0;
int m = 0;
int s = 0;
struct Node {
  int weight = 0;
  vector<int>child;
};
vector<Node>vec;
bool Cmp(int &lhs, int &rhs) {
  return vec[lhs].weight > vec[rhs].weight;
}
int f = 0;
void DFS(vector<Node> &path, int sum, int index) {
	if (sum > s)  return ;
  if (sum == s) {
    if (path.back().child.size() != 0)
      return;
    else {
      if (f)
        printf("\n");
      f = 1;
      int flag = 0;
      for (auto item : path) {
        if (flag)
          printf(" ");
        flag = 1;
        printf("%d", item.weight);
      }
    }
    return ;
  }
  else {
    Node root = vec[index];
    for (int i = 0;i < root.child.size();++i) {
      int x = root.child[i]; 
      path.push_back(vec[x]);
      DFS(path, sum + vec[x].weight, x);
      path.pop_back();
    }
  }
}
void Preorder(int index) {
	auto root = vec[index];
	if (root.weight == 0)
		return ;
	printf(" %d", index);
	for (int i = 0;i < root.child.size();++i)
		Preorder(root.child[i]);	
} 
int main() {
  scanf("%d %d %d", &n, &m, &s);
  for (int i = 0;i < n;++i) {
    int e = 0;
    scanf("%d", &e);
    Node ins;
    ins.weight = e;
    vec.push_back(ins);
  }
  for (int i = 0;i < m;++i) {
    int id = 0;
    int size = 0;
    scanf("%d %d", &id, &size);
    vec[id].child.clear();
    for (int j = 0;j < size;++j) {
      int ch = 0;
      scanf("%d", &ch); 
      vec[id].child.push_back(ch);
    }
//    for (auto item : vec[id].child) {
//    	cout << item << " ";
//		}
    sort(vec[id].child.begin(), vec[id].child.end(), Cmp);
  }
//  Preorder(0);
  vector<Node>path;
  path.push_back(vec[0]);
  DFS(path, vec[0].weight, 0);
  return 0;
}

