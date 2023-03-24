#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	string str, tmp;
	int ans = 0;
	cin >> str;
	
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '(' && str[i + 1] == ')') {
			ans += tmp.size();
			i++;
			continue;
		}

		if (str[i] == '(') {
			tmp.push_back('(');
		}
		if (str[i] == ')') {
			ans += 1;
			tmp.pop_back();
		}
	}
	cout << ans;
	return 0;
}