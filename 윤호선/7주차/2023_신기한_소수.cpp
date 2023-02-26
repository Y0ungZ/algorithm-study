#include <iostream>
#include <string>
#include <math.h>
using namespace std;

bool isPrime(string num) {
	int number = stoi(num);
	for (int i = 2; i <= sqrt(number); i++) {
		if (number % i == 0)return false;
	}
	return true;
}

int sol(string num, int n) {
	if (num.size()!=0&&!isPrime(num)) return 0;
	if (num.size() == n) {
		cout << num << "\n";
		return 0;
	}
	
	for (int i = 0; i < 10; i++) {
		if (i == 0 && num.size() == 0)continue;
		if (i == 1 && num.size() == 0)continue;
		sol(num + to_string(i), n);
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	sol("", n);
	return 0;
}