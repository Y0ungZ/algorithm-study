#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int Map[101][101];
int N, ans = 100000;

int set_Map(int num, int x,int y, vector<vector<int>>& map) {
	queue<pair<int, int>> que;
	vector<vector<int>> visited(N, vector<int>(N));

	que.push({ x,y });
	Map[x][y] = num;

	while (!que.empty()) {
		int cx = que.front().first;
		int cy = que.front().second;
		que.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (0 > nx || nx >= N || 0 > ny || ny >= N)continue;
			if (map[nx][ny] == 0)continue;
			if (Map[nx][ny] == num)continue;

			Map[nx][ny] = num;
			que.push({ nx,ny });
		}
	}
	return 0;
}
int make_bridge(int island_num,int x,int y) {
	queue<pair<int, int>> que;
	vector<vector<int>> visited(N, vector<int>(N));
	
	que.push({ x,y });
	visited[x][y] = 1;

	while (!que.empty()) {
		int cx = que.front().first;
		int cy = que.front().second;
		que.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (0 > nx || nx >= N || 0 > ny || ny >= N)continue;
			if (visited[nx][ny] != 0)continue;
			if (Map[nx][ny] == island_num)continue;
			if (Map[nx][ny] != 0) {
				if (ans > visited[cx][cy] - 1)ans = visited[cx][cy] - 1;
				return 0;
			}
			visited[nx][ny] = visited[cx][cy] + 1;
			que.push({ nx,ny });
		}
	}
	return 0;
}

int main() {

	cin >> N;
	vector<vector<int>> map(N, vector<int>(N));
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	int num = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 1 && Map[i][j] == 0)set_Map(++num, i, j, map);
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (Map[i][j] != 0) make_bridge(Map[i][j], i, j);
		}
	}
	cout << ans;

	return 0;
}