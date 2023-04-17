#include <iostream>
#include <vector>
#include <queue>
#define MAX 700000001
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, e;
	cin >> n >> e;
	vector<vector<pair<int, int>>> vec(n + 1,vector<pair<int,int>>());

	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b>> c;
		vec[a].push_back({ b,c });
		vec[b].push_back({ a,c });
	}

	int v[2];
	vector<vector<int>> table(2, vector<int>(n + 1,MAX));
	
	for (int i = 0; i < 2; i++) {
		cin >> v[i];

		priority_queue<pair<int, int>>pq;
		pq.push({ 0,v[i]});
		table[i][v[i]] = 0;

		while (!pq.empty()) {
			int cur = pq.top().second;
			int val = -pq.top().first;
			pq.pop();

			if (table[i][cur] < val)continue;

			for (int j = 0; j < vec[cur].size(); j++) {
				int next = vec[cur][j].first;
				int n_val = vec[cur][j].second;

				if (table[i][next] <= val + n_val)continue;
				table[i][next] = val + n_val;
				pq.push({ -table[i][next],next });
			}
		}
	}
	int ans = min(table[0][1] + table[0][v[1]] + table[1][n], table[1][1] + table[1][v[0]] + table[0][n]);
	if (ans >= MAX)ans = -1;
	cout << ans;
	return 0;
}