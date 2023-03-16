#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N;
	cin >> N;

	vector<int> apple(N);
	int sum = 0;
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		cin >> apple[i];
		sum += apple[i];
		cnt += apple[i] / 2;
	}

	if (sum % 3 != 0) {
		cout << "NO\n";
		return 0;
	}
	
	if (cnt >= sum / 3) {
		cout << "YES\n";
	}
	else {
		cout << "NO\n";
	}

	return 0;
}