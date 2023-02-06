#include <iostream>
using namespace std;

int answer = 0;

void dfs(string str, string S) {
	if (str.length() == 0 || answer == 1) {
		return;
	}
	if (str.length() == S.length()) {
		if (str == S) {
			answer = 1;
		}
		return;
	}
	string temp_A = str;
	if (str[str.length() - 1] == 'A') {
		temp_A.pop_back();
		dfs(temp_A, S);
	}
	if (str[0] == 'B') {
		string temp_B = "";
		for (int j = str.length() - 1; j > 0; j--) {
			temp_B += str[j];
		}
		dfs(temp_B, S);
	}
}

int main()
{
	string S, T;
	cin >> S >> T;

	dfs(T, S);

	cout << answer << "\n";
}