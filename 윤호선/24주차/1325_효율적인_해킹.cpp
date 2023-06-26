#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, M, max_cnt = -1;
	vector<int> ans;
	cin >> N >> M;

	vector<vector<int>> table(N + 1,vector<int>());
	for (int i = 0; i < M; i++) {
		int com1, com2;
		cin >> com1 >> com2;
		table[com2].push_back(com1);
	}

	for (int i = 1; i <= N; i++) {
		int cnt = 0;
		vector<int> visited(N + 1);
		queue<int> que;

		que.push(i);
		visited[i] = 1;
		while (!que.empty()) {
			int cur = que.front();
			que.pop();
			cnt++;
			for (int j = 0; j < table[cur].size(); j++) {
				int next = table[cur][j];
				if (visited[next])continue;
				que.push(next);
				visited[next] = 1;
			}
		}

		if (max_cnt == cnt)ans.push_back(i);
		if (max_cnt < cnt) {
			ans.clear();
			ans.push_back(i);
			max_cnt = cnt;
		}
	}

	for (int i = 0; i <ans.size(); i++) {
		cout << ans[i] << " ";
	}
	return 0;
}