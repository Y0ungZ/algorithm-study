#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	int T;
	cin >> T;

	while (T != 0) {
		int N;
		cin >> N;

		vector<string> phone_no(N);
		for (int i = 0; i < N; i++) {
			cin >> phone_no[i];
		}

		sort(phone_no.begin(), phone_no.end());

		int result = 1;
		for (int i = 1; i < phone_no.size(); i++) {
			int length = 0;
			for (int j = 0; j < phone_no[i - 1].length(); j++) {
				if (phone_no[i - 1][j] == phone_no[i][j]) {
					length++;
				}
			}
			if (length == phone_no[i - 1].length()) {
				result = 0;
				break;
			}
		}

		if (result == 0) {
			cout << "NO\n";
		}
		else {
			cout << "YES\n";
		}

		T--;
	}
}