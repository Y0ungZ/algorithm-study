#include <iostream>
#include <cmath>
using namespace std;

bool prime(int num) {
	for (int i = 2; i <= sqrt(num); i++) {
		if (num % i == 0) return false;
	}
	return true;
}

int check(int num, int chiper, int N){
	if (chiper == N) {
		cout << num << "\n";
		return 0;
	}

	for (int i = 0; i < 10; i++) {
		if (prime(num * 10 + i)) {
			check(num * 10 + i, chiper + 1, N);
		}
	}
	return 0;
}

int main()
{
	int N;
	cin >> N;

	check(2, 1, N);
	check(3, 1, N);
	check(5, 1, N);
	check(7, 1, N);

	return 0;
}