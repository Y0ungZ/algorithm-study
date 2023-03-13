#include <iostream>
#include <algorithm>
using namespace std;

long long count(long long N, long long k) {
	long long cnt = 0;
	
	for (long long i = 1; i <= N; i++) {
		cnt += min(N, k / i);
	}

	return cnt;
}

long long binary_search(long long N, long long k) {
	long long low = 1;
	long long high = N * N;
	long long mid = 0;
	long long cnt = 0;

	while (low <= high) {
		mid = (low + high) / 2;

		cnt = count(N, mid);

		if (cnt >= k) high = mid - 1;
		else low = mid + 1;
	}

	return low;
}

int main()
{
	long long N;
	long long k;
	cin >> N >> k;
	
	long long answer = binary_search(N, k);
	cout << answer << "\n";
	
	return 0;
}