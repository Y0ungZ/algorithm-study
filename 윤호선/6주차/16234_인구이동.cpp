#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, l, r, res = 0;
	cin >> n >> l >> r;
	vector<vector<int>> map(n, vector<int>(n));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	while (++res) {
		vector<vector<int>> next_map(n, vector<int>(n, -2));

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (next_map[i][j] == -2) {

					int sum = map[i][j];
					int cnt = 1;
					int cur_x = -1, cur_y = -1;

					queue<pair<int, int>> que;
					que.push({ i,j });
					next_map[i][j] = -1;

					while (!que.empty()) {
						cur_x = que.front().first;
						cur_y = que.front().second;
						que.pop();

						for (int k = 0; k < 4; k++) {
							int next_x = cur_x + dx[k];
							int next_y = cur_y + dy[k];

							if (0 > next_x || next_x >= n || 0 > next_y || next_y >= n) continue;

							int biff = abs(map[cur_x][cur_y] - map[next_x][next_y]);
							if (l > biff || biff > r)continue;
							if (next_map[next_x][next_y] != -2) continue;
							
							next_map[next_x][next_y] = -1;
							que.push({ next_x,next_y });
							sum += map[next_x][next_y];
							cnt++;
						}
					}

					int per_num = sum / cnt;
					que.push({ cur_x,cur_y });
					next_map[cur_x][cur_y] = per_num;

					while (!que.empty()) {
						cur_x = que.front().first;
						cur_y = que.front().second;
						que.pop();

						for (int k = 0; k < 4; k++) {
							int next_x = cur_x + dx[k];
							int next_y = cur_y + dy[k];

							if (0 > next_x || next_x >= n || 0 > next_y || next_y >= n) continue;
							if (next_map[next_x][next_y] != -1) continue;
							
							next_map[next_x][next_y] = per_num;
							que.push({ next_x,next_y });
						}
					}
				}
			}
		}
		if (map == next_map) {
			cout << res - 1;
			break;
		}
		map = next_map;
	}
	return 0;
}