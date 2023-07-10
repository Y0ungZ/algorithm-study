#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int GCD(int x, int y) {
	if (x % y == 0) {
		return y;
	}
	else {
		return GCD(y, x % y);
	}
}

int main()
{
	int N;
	cin >> N;

	vector<int> arr(N);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());

	int gcd = arr[1] - arr[0];
	for (int i = 2; i < N; i++) {
		gcd = GCD(gcd, arr[i] - arr[i - 1]);
	}

	vector<int> answer;
	for (int i = 2; i * i <= gcd; i++) {
		if (gcd % i == 0) {
			answer.push_back(i);
			if (i != gcd / i) {
				answer.push_back(gcd / i);
			}
		}
	}

	answer.push_back(gcd);
	sort(answer.begin(), answer.end());

	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << " ";
	}

	return 0;
}