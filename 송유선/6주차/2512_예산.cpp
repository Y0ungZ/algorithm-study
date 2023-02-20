#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int answer;

void binary_search(int budget, vector<int>& money, int N) {
	int left = 0, right = money[N - 1];

	while (left <= right) {
		int mid = (left + right) / 2;
		int total = 0;

		for (int i = 0; i < N; i++) {
			if (money[i] > mid) {
				total += mid;
			}
			else {
				total += money[i];
			}
		}
		if (total > budget) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
			answer = mid;
		}
	}
}

int main()
{
	int N;
	cin >> N;

	vector<int> money(N);
	for (int i = 0; i < N; i++) {
		cin >> money[i];
	}

	int budget;
	cin >> budget;

	sort(money.begin(), money.end());

	int sum = 0;
	for (int i = 0; i < N; i++) {
		sum += money[i];
	}

	if (budget >= sum) {
		cout << money[N - 1] << "\n";
	}
	else {
		binary_search(budget, money, N);
		cout << answer << "\n";
	}

	return 0;
}