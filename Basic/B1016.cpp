#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
int main() {
	string a;
	string d_a;
	string b;
	string d_b;
	cin >> a >> d_a >> b >> d_b;
	int n_d_a = 0;
	int n_d_b = 0;
	for(const auto &item : a) {
		if (string{item} == d_a) {
			++n_d_a;
		}
	}
	for(const auto &item : b) {
			if (string{item} == d_b) {
				 ++n_d_b;
		}
	}
	string p_a{"0"};
	string p_b{"0"};
	while(n_d_a--) {
		p_a += d_a;
	}
	while(n_d_b--) {
		p_b += d_b;
	}
	long long sum = stoi(p_a) + stoi(p_b);
	sum != 0? cout << sum : cout << 0;
	return 0;
} 
