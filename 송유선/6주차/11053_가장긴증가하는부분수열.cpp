#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N;
	cin >> N;

	vector<int> A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	vector<int> dp(N, 1);
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (A[i] > A[j]) {
				dp[i] = max(dp[j] + 1, dp[i]);
			}
		}
	}

	int answer = 0;
	for (int i = 0; i < N; i++) {
		answer = max(answer, dp[i]);
	}
	cout << answer << "\n";

	return 0;
}