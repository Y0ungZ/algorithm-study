#include <iostream>
#include <vector>
using namespace std;

int binary_search(long long left, long long right, vector<long long>& lec, int M) {
	while (left <= right) {
		long long sum = 0;
		int cnt = 0;
		long long mid = (left + right) / 2;

		for (int i = 0; i < lec.size(); i++) {
			if (sum + lec[i] > mid) {
				cnt++;
				sum = 0;
			}
			sum += lec[i];
		}

		if (sum != 0) cnt++;

		if (cnt > M) left = mid + 1;
		else right = mid - 1;
	}

	return left;
}

int main()
{
	int N, M;
	cin >> N >> M;

	long long sum = 0;
	long long max_lec = 0;
	vector<long long> lecture(N);
	for (int i = 0; i < N; i++) {
		cin >> lecture[i];
		sum += lecture[i];
		max_lec = max(max_lec, lecture[i]);
	}

	int answer = binary_search(max_lec, sum, lecture, M);
	cout << answer << "\n";

	return 0;
}