#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	cin >> N;

	vector<int> solution(N);
	for (int i = 0; i < N; i++) {
		cin >> solution[i];
	}
	
	sort(solution.begin(), solution.end());

	int start = 0, end = N - 1;
	long long sum = 0;

	vector<tuple<int, int,long long>> answer;

	while (1) {
		sum = solution[start] + solution[end];

		answer.push_back(make_tuple(start, end, sum));

		if (start == end) {
			break;
		}

		if (sum > 0) end--;
		else if (sum <= 0) start++;
	}

	int ans = 0;
	long long total = abs(get<2>(answer[0]));
	for (int i = 0; i < answer.size() - 1; i++) {
		if (abs(get<2>(answer[i])) == 0) {
			ans = i;
			break;
		}
		else {
			if (total >= abs(get<2>(answer[i]))) {
				total = abs(get<2>(answer[i]));
				ans = i;
			}
		}
	}

	cout << solution[get<0>(answer[ans])] << " " << solution[get<1>(answer[ans])] << endl;
	
	return 0;
}