#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, val, ans = 0;
	cin >> N;
	vector<int>values;
	vector<int>me(1), ryou(1);

	for (int i = 1; i <= N; i++) {
		cin >> val;
		values.push_back(val);
	}

	for (int i = 1; i <= N; i++) {
		if (i % 2 == 1) {
			me.push_back(values[i - 1]);
			ryou.push_back(values[N - i]);
			me[i / 2 + 1] += me[i / 2];
			ryou[i / 2 + 1] += ryou[i / 2];
		}
	}

	for (int i = 0; i <= N / 2; i++) {
		if (ans < me[i] + ryou[N / 2 - i])ans = me[i] + ryou[N / 2 - i];
	}
	for (int i = 1; i <= N / 2-1; i++) {
		if (ans < me[i] + ryou[N / 2 - i + 1] - values.back())ans = me[i] + ryou[N / 2 - i + 1] - values.back();
	}
	cout << ans;
	return 0;
}