#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

string str;
int sol(string s, vector<int>& check, int start_idx) {
	if (s == "")return 0;

	char c = *min_element(s.begin(), s.end());
	int n = min_element(s.begin(), s.end()) - s.begin();

	check[start_idx + n] = 1;
	for (int i = 0; i < check.size(); i++) {
		if (check[i] == 1) cout << str[i];
	}
	cout << "\n";

	sol(s.substr(n + 1), check, start_idx + n + 1);
	sol(s.substr(0, n), check, start_idx);

	return 0;
}

int main() {

	cin >> str;
	vector<int> check(str.length());
	sol(str, check,0);

	return 0;
}