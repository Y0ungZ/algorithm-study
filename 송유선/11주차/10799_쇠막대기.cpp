#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str;
	cin >> str;

	int cnt = 0;
	int sum = 0;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '(') {
			if (str[i + 1] == ')') {
				sum += cnt;
				i++;
			}
			else {
				cnt++;
			}
		}
		else if (str[i] == ')' && str[i - 1] != '(') {
			sum++;
			cnt--;
		}
	}

	cout << sum << "\n";
}