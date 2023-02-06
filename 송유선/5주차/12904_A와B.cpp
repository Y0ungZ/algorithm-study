#include <iostream>
using namespace std;

int main()
{
	string S, T;
	cin >> S >> T;

	while (1) {
		if (S.length() == T.length()) {
			if (S == T) {
				cout << "1\n";
				break;
			}
			else {
				cout << "0\n";
				break;
			}
		}

		if (T[T.length() - 1] == 'A') {
			T.pop_back();
		}
		else {
			T.pop_back();
			string temp = "";
			for (int j = T.length() - 1; j >= 0; j--) {
				temp += T[j];
			}
			T = temp;
		}
	}
	
	return 0;
}