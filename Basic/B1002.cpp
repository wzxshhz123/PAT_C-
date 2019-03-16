#include <cstdio>
#include <string>
using namespace std;
char dict[10][5] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
int main() {
  long long sum = 0;
  char ch;
  while ((ch = getchar()) != '\n') {
      int num = ch - 48;
      sum += num;
  }
  auto str = to_string(sum);
  int i = 1;
  for (const auto &item : str) {
    int index = item - 48;
    if (i == 1) {
      printf("%s",dict[index]);
    }
    else {
      printf(" %s",dict[index]);  
    }
    ++i;
  }
  // printf("\n");
  return 0;
}