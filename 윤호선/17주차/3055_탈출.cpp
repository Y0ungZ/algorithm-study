#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

struct Pos {
	int x = -1;
	int y = -1;
	int dis = -1;
};

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int R, C;
	cin >> R >> C;

	Pos S;
	queue<Pos> que;
	vector<vector<char>> map(R, vector<char>(C));
	vector<vector<int>> visited(R, vector<int>(C));
	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			cin >> map[r][c];
			if (map[r][c] == '*') {
				que.push({ r,c,-1 });
				visited[r][c] = -1;
			}
			if (map[r][c] == 'S')S = { r,c,1 };
		}
	}

	que.push(S);
	visited[S.x][S.y] = 1;

	while (!que.empty()) {
		int x = que.front().x;
		int y = que.front().y;
		int dis = que.front().dis;
		que.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= R || ny < 0 || ny >= C)continue;
			if (map[nx][ny] == 'D' && dis != -1) {
				cout << dis;
				return 0;
			}
			if (map[nx][ny] == 'D' || map[nx][ny] == 'X')continue;
			if (dis == -1) {
				if (visited[nx][ny] == -1)continue;
				visited[nx][ny] = -1;
				que.push({ nx,ny,-1 });
			}
			else {
				if (visited[nx][ny] != 0)continue;
				visited[nx][ny] = 1;
				que.push({ nx,ny,dis + 1 });
			}
		}
	}
	cout << "KAKTUS";
	return 0;
}
