#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

	int n, m, x, y, ans = 0;
	cin >> n >> m;

	vector<vector<int>> map(n, vector<int>(m));
	vector<vector<int>> tmp_map(n, vector<int>(m, -1));
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] != 0) {
				x = i;
				y = j;
			}
		}
	}
	
	while (++ans) {
		int iceberg_cnt = 0, sx, sy;
		queue<pair<int, int>> que;
		que.push({ x,y });
		tmp_map[x][y] = 0;
		
		while (!que.empty()) {
			int cnt = 0;
			x = que.front().first;
			y = que.front().second;
			que.pop();

			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx < 0 || nx >= n || ny < 0 || ny >= m)continue;
				if (map[nx][ny] <= 0) {
					cnt++;
					continue;
				}
				if (tmp_map[nx][ny] != -1)continue;
				tmp_map[nx][ny] = 0;
				que.push({ nx,ny });
			}

			tmp_map[x][y] = map[x][y] - cnt;
			if (tmp_map[x][y] < 0)tmp_map[x][y] = 0;
			if (tmp_map[x][y] > 0) {
				iceberg_cnt++;
				sx = x;
				sy = y;
			}
		}
        
		fill(map.begin(), map.end(), vector<int>(m,-1));
		
		int ice_cnt = 0;
		que.push({ sx,sy });
		map[sx][sy] = tmp_map[sx][sy];
        
		while (!que.empty()) {
			ice_cnt++;
			x = que.front().first;
			y = que.front().second;
			que.pop();
			
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx < 0 || nx >= n || ny < 0 || ny >= m)continue;
				if (map[nx][ny] != -1)continue;
				if (tmp_map[nx][ny] <= 0)continue;
				map[nx][ny] = tmp_map[nx][ny];
				que.push({ nx,ny });
			}
		}
        
		if (iceberg_cnt == 0)break;
		if (iceberg_cnt != ice_cnt) {
			cout << ans;
			return 0;
		}
        
		fill(tmp_map.begin(), tmp_map.end(), vector<int>(m,-1));
		x = sx;
		y = sy;
	}
	cout << "0";
	return 0;
}