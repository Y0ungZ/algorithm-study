#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	vector<int>v(1000001);
	int N, T, S, start = 10000000;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> T >> S;
		v[S] += T;
		if (S < start)start = S;
	}

	int ans, temp = 0;
	ans = start - v[start];
	temp = start;
	for (int i = start + 1; i < 1000001; i++) {
		if (v[i] == 0)continue;
		if (i - temp < v[i]) {
			ans -= v[i] - i + temp;
			temp = i;
		}
		else {
			temp += v[i];
		}

		if (ans < 0) {
			cout << "-1";
			return 0;
		}
	}
	cout << ans;
	return 0;
}