#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	vector<int> dp(n, -100000001);
	dp[0] = arr[0];
	for (int i = 1; i < n; i++) {
		dp[i] = max({ dp[i], dp[i - 1] + arr[i], arr[i] });
	}

	int answer = -100000001;
	for (int i = 0; i < n; i++) {
		answer = max(dp[i], answer);
	}
	cout << answer << "\n";

	return 0;
}