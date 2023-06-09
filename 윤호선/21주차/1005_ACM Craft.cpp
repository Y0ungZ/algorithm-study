#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int test_case;
	cin >> test_case;

	while (test_case--) {

		//입력
		int N, K; cin >> N >> K;
		int target;
		vector<int> time(N + 1);
		vector<int> rq_num(N + 1);
		vector<vector<int>> next_buildings(N + 1,vector<int>());
		vector<int> min_time(N + 1);

		for (int i = 0; i < N; i++) {
			cin >> time[i + 1];
		}
		for (int i = 0; i < K; i++) {
			int a, b;
			cin >> a >> b;
			++rq_num[b];
			next_buildings[a].push_back(b);
		}
		cin >> target;

		//que를 이용하여 순서대로 방문
		queue<int> que;
		for (int i = 0; i < N; i++) {
			if (rq_num[i + 1] == 0) {
				que.push(i + 1);
				min_time[i + 1] = time[i + 1];
			}
		}
		while (!que.empty()) {
			int cur = que.front();
			que.pop();

			for (int i = 0; i < next_buildings[cur].size(); i++) {
				int nb = next_buildings[cur][i];
				--rq_num[nb];
				if (min_time[nb] < min_time[cur])min_time[nb] = min_time[cur];
				if (rq_num[nb] == 0) {
					que.push(nb);
					min_time[nb] += time[nb];
				}
			}
		}

		//결과 출력
		cout << min_time[target] << "\n";
	}
	return 0;
}