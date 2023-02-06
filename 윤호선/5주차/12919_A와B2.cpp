#include <iostream>
#include <string>
using namespace std;

bool comp(string s1, string s2) {
	int len = s1.length();
	for (int i = 0; i < len; i++) {
		if (s1[len - 1 - i] != s2[i])return false;
	}
	return true;
}

int sol(bool flag, string& s, string t) {
	if (s.length() == t.length()) {
		if (!flag && s == t)return 1;
		if (flag && comp(s, t))return 1;
		return 0;
	}

	if (!flag && t.back() == 'A') {
		if (sol(false, s, t.substr(0, t.length() - 1)))return 1;
	}
	if (flag && t[0] == 'A') {
		if (sol(true, s, t.substr(1, t.length() - 1)))return 1;
	}
	if (!flag&&t[0] == 'B') {
		if (sol(true, s, t.substr(1, t.length() - 1)))return 1;
	}
	if (flag&&t.back() == 'B') {
		if (sol(false, s, t.substr(0, t.length() - 1)))return 1;
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string S, T;
	cin >> S >> T;

	cout << sol(false, S, T);
	return 0;
}