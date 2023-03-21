#include <iostream>
#include <map>
using namespace std;

int sum[200001] = { 0 };

int main()
{
	int N, K;
	cin >> N >> K;

	for (long long i = 1; i <= N; i++) {
		long long temp;
		cin >> temp;
		sum[i] = sum[i - 1] + temp;
	}

	map<long long, long long> m;
	long long answer = 0;
	for (long long i = 1; i <= N; i++) {
		if (sum[i] == K) answer++;
		answer += m[sum[i] - K];
		m[sum[i]]++;
	}

	cout << answer << "\n";

	return 0;
}