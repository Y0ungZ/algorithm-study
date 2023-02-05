#include <iostream>
#include <stack>
#include <vector>
using namespace std;

string str;
char temp = 'Z';
stack<int> st;

void min_check(int start, int end, vector<int>& check)
{
	for (int i = start; i < end; i++) {
		if (str[i] - '0' < temp - '0' && check[i] == 0) {
			temp = str[i];
			start = i;
		}
	}
	check[start] = 1;
	st.push(start);

	int cnt = 0;
	for (int i = 0; i < str.length(); i++) {
		if (check[i] != 0) {
			cout << str[i];
			cnt++;
		}
	}
	cout << "\n";

	if (cnt == str.length()) {
		return;
	}
	else {
		if (start == str.length() - 1) {
			st.pop();
		}
		while (!st.empty() && check[st.top() + 1] != 0) {
			start = st.top() + 1;
			st.pop();
		}
		if (!st.empty() && check[st.top() + 1] == 0) {
			start = st.top() + 1;
			temp = str[start];
		}
		if (st.empty()) {
			start = 0;
			temp = str[0];
		}
		min_check(start, end, check);
	}	
}

int main()
{
	cin >> str;

	vector<int> check(str.length());

	min_check(0, str.length(), check);

	return 0;
}