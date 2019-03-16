#include<iostream>
using namespace std;
int num = 0;
int conunt = 0;
int main() {
  while(cin >> num) {
    while(true) {
      if (num % 2 == 0) {
        num /= 2;
        ++conunt;
        continue;
      }
      if (num == 1) {
        std::cout << conunt;
        break;
      }
      num = (3 * num + 1) / 2;
      ++conunt;
      continue;
    }
  }
  return 0;
}