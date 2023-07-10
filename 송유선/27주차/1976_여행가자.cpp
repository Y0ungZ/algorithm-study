#include <iostream>
#include <vector>
using namespace std;

int answer = 0;

int path(vector<vector<int>>& city, vector<int>& plan, vector<int>& visit, int now, int next) {
	visit[now] = 1;
	if (city[now].size()) {
		if (visit[next] == 0) {
			for (int j = 0; j < city[now].size(); j++) {
				if (next == city[now][j]) {
					visit[city[now][j]] = 1;
					return 1;
				}
			}
			for (int j = 0; j < city[now].size(); j++) {
				if (visit[city[now][j]] == 0) {
					if (path(city, plan, visit, city[now][j], next)) {
						return 1;
					}
				}
			}
		}
	}
	else {
		answer = 1;
		return 1;
	}

	return 0;
}

int main()
{
	int N, M;
	cin >> N >> M;

	vector<vector<int>> connect(N, vector<int>(N));
	vector<vector<int>> city(N + 1);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> connect[i][j];
			if (connect[i][j] == 1) {
				city[i + 1].push_back(j + 1);
			}
		}
	}

	vector<int> plan(M);
	for (int i = 0; i < M; i++) {
		cin >> plan[i];
	}

	for (int i = 0; i < plan.size() - 1; i++) {
		if (plan[i] == plan[i + 1]) {
			continue;
		}
		if (answer == 1) {
			break;
		}

		vector<int> visit(N + 1);

		if (!path(city, plan, visit, plan[i], plan[i + 1])) {
			answer = 1;
			break;
		}
	}

	if (answer == 0) {
		cout << "YES\n";
	}
	else {
		cout << "NO\n";
	}

	return 0;
}