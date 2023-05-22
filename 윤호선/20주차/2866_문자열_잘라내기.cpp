#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int r, c;cin >> r >> c;
	int cnt = -1;
	
	vector<string> words(r);
	set<string> words_set;

	for (int i = 0; i < r; i++) {
		cin >> words[i];
	}
	for (int i = 0; i < c; i++) {
		string str;
		for (int j = r-1; j >-1; j--) {
			str.push_back(words[j][i]);
		}
		words_set.insert(str);
	}

	set<string>::iterator it;
	while (words_set.size() == c) {
		for (it = words_set.begin(); it != words_set.end(); ) {
			string st = *it;
			st.pop_back();
			words_set.erase(it++);
			words_set.insert(st);
		}
		cnt++;
	}
	cout << cnt;
	return 0;
}