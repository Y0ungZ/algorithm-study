#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int cnt(int m, int N) {
	int sum = 0;
	for (int i = 1; i <= N; i++) {
		sum += min(m / i, N);
	}
	return sum;
}

int sol(int s, int e, int K, int N) {
	int mid;

	while (s <= e) {
		mid = (s + e) / 2;

		if (cnt(mid, N) >= K) e = mid - 1;
		else s = mid + 1;
	}
	return s;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, K;
	cin >> N >> K;

	cout << sol(1, K, K, N);

	return 0;
}