#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<int> sum;
	vector<int> min_sum;
	int n, num;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> num;
		sum.push_back(num);

		if (i == 0) {
			min_sum.push_back(sum[i]);
			continue;
		}
		sum[i] += sum[i - 1];
		min_sum.push_back(min(min_sum[i - 1], sum[i]));
	}
	
	int ans = sum[0];
	for (int i = 1; i < n; i++) {
		if (ans < sum[i])ans = sum[i];
		if (ans < sum[i] - min_sum[i - 1])ans = sum[i] - min_sum[i-1];
	}
	cout << ans;
	return 0;
}