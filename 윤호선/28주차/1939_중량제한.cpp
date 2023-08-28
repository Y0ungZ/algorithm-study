#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int N, M, start, end;
	cin >> N >> M;
	vector<vector<pair<int,int>>> bridge(N + 1, vector<pair<int,int>>());
	vector<int> max_val(N + 1, -1);
	priority_queue<pair<int, int>> que;

	for (int m = 0; m < M; m++) {
		int i1, i2, val;
		cin >> i1 >> i2 >> val;
		if (i1 == i2)continue;
		bridge[i1].push_back({ val,i2 });
		bridge[i2].push_back({ val,i1 });
	}
	cin >> start >> end;
	
	que.push({ 0,start });
	while (!que.empty()) {
		int cur = que.top().second;
		int c_val = que.top().first;
		que.pop();

		if (max_val[cur]==0||max_val[cur] >= c_val)continue;
		max_val[cur] = c_val;
		for (int i = 0; i < bridge[cur].size(); i++) {
			int n = bridge[cur][i].second;
			int n_val = bridge[cur][i].first;
			int t=max(max_val[n], min(c_val, n_val));

			if (t == 0)t = n_val;
			if (t <= max_val[n])continue;
			que.push({ t,n });
		}
	}
	cout << max_val[end];
	return 0;
}