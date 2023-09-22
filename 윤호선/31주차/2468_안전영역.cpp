#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dx[4] = { 0,1,-1,0 };
int dy[4] = { 1,0,0,-1 };
int bfs(int x, int y, int c, int h, vector<vector<int>>& map, vector<vector<int>>& visited) {
	queue<pair<int, int>> que;
	que.push({ x,y });
	visited[x][y] = c;

	while (!que.empty()) {
		int cx = que.front().first;
		int cy = que.front().second;
		que.pop();

		for (int k = 0; k < 4; k++) {
			int nx = cx + dx[k];
			int ny = cy + dy[k];
			if (nx < 0 || visited.size() <= nx || ny < 0 || visited.size() <= ny)continue;
			if (map[nx][ny] <= h)continue;
			if (visited[nx][ny] != 0)continue;
			visited[nx][ny] = c;
			que.push({ nx,ny });
		}
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
		
	int N;cin >> N;
	int maxHeight = -1, maxCnt = -1;

	vector<vector<int>> map(N, vector<int>(N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (maxHeight < map[i][j])maxHeight = map[i][j];
		}
	}

	int height = maxHeight;
	while (height--) {
		int cnt = 1;
		vector<vector<int>> visited(N, vector<int>(N));
		
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (visited[i][j] != 0)continue;
				if (map[i][j] <= height)continue;

				bfs(i, j, cnt, height, map, visited);
				++cnt;
			}
		}
		if (maxCnt < cnt - 1)maxCnt = cnt - 1;
	}
	cout << maxCnt;
	return 0;
}