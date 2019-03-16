#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;
unordered_map<string, vector<int>> h; 
int main() {
	int n = 0;
	scanf("%d", &n);
	while (n--) {
		int id = 0;
		scanf("%d", &id);
		
		getchar();
		string title;
		getline(cin, title);
		h[title].push_back(id);
		
		string author;
		getline(cin, author);
		h[author].push_back(id);
		
		string key_words;
		getline(cin, key_words);
		int i = 0;
		while (key_words.find(" ", i) != string::npos) {
			int pos = key_words.find(" ", i);
			string k = key_words.substr(i, pos - i);
			h[k].push_back(id);
			i = pos + 1;
		}
		string k = key_words.substr(i, key_words.size() - i);
		h[k].push_back(id);
		
		string publisher;
		getline(cin, publisher);
		h[publisher].push_back(id);
		
		string year;
		cin >> year;
		h[year].push_back(id);
	}
	int query = 0;
	scanf("%d", &query);
	getchar();
	while (query--) {
		string str;
		getline(cin, str);
		string res = str;
		int pos = str.find(" ");
		str.erase(0, pos);
		str.erase(str.begin());
		int flag = 0;
		
		cout << res << endl;
		if (h.count(str) != 0) {
			sort(h[str].begin(), h[str].end());
			for (auto item : h[str]) {
				printf("%07d\n", item);
			}
		}
		else {
			printf("Not Found\n");
		}
	}
	return 0;
}
