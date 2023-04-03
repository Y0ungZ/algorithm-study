#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N, D;
	cin >> N >> D;

	vector<int> highway(D + 1);
	for (int i = 0; i <= D; i++) {
		highway[i] = i;
	}

	vector<vector<int>> distance(N, vector<int>(3));
	for (int i = 0; i < N; i++) {
		cin >> distance[i][0] >> distance[i][1] >> distance[i][2];
	}

	sort(distance.begin(), distance.end());
	for (int i = 0; i < N; i++) {
		if (distance[i][1] <= D && distance[i][1] - distance[i][0] > distance[i][2]) {
			for (int j = 0; j <= distance[i][1]; j++) {
				for (int k = 0; k <= j; k++) {
					if (j == distance[i][1]) {
						highway[j] = min({ highway[j], highway[k] + j - k, highway[distance[i][0]] + distance[i][2] });
					}
					else {
						highway[j] = min(highway[j], highway[k] + j - k);
					}
				}
			}
		}
	}

	for (int i = 0; i <= D; i++) {
		for (int j = 0; j <= i; j++) {
			highway[i] = min(highway[i], highway[j] + i - j);
		}
	}

	cout << highway[D] << "\n";

	return 0;
}