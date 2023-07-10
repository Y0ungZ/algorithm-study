#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int testcase;
	cin >> testcase;

	while (testcase--) {
		string ans = "YES";
		int N;
		cin >> N;
		vector<string> num(N);

		for (int i = 0; i < N; i++){
			cin >> num[i];
		}
		//정렬한 후, 바로 아래 있는 숫자랑 비교
		sort(num.begin(), num.end());
		for (int i = 1; i < N; i++) {
			string num1 = num[i - 1];
			string num2 = num[i];
			if (num2.length() < num1.length())continue;
			if (num2.substr(0, num1.length()) == num1) {
				ans = "NO";
				break;
			}
		}
		cout << ans << "\n";
	}

	return 0;
}