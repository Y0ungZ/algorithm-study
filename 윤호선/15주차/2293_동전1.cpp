#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, k;
	cin >> n >> k;
	vector<int> coins(n + 1);
	vector<int> dp(k + 1);

	for (int i = 1; i <= n; i++) {
		cin >> coins[i];
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			if (j > coins[i])dp[j] += dp[j - coins[i]];
			if (j == coins[i])dp[j] += 1;
		}
	}
	cout << dp[k];
	return 0;
}