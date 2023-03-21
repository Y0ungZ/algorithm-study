#include <iostream>
#include <math.h>
#include <vector>
#include <queue>
#include <set>
using namespace std;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

struct Pos
{
	int bit;
	int x;
	int y;

	bool operator<(const Pos &var) const
	{
		if (bit == var.bit) {
			if (x == var.x) {
				return y > var.y;
			}
			return x > var.x;
		}
		return bit > var.bit;
	}
};

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int N, M;
	cin >> N >> M;

	vector<vector<char>> maze(N, vector<char>(M,'.'));
	set<Pos> visited;
	Pos start;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> maze[i][j];
			if (maze[i][j] == '0')start = { 0,i,j };
		}
	}
	queue<pair<Pos,int>> que;
	que.push({ start,0 });
	visited.insert(start);

	while (!que.empty()) {
		int cbit = que.front().first.bit;
		int cx = que.front().first.x;
		int cy = que.front().first.y;
		int cnt = que.front().second;
		que.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M)continue;
			if (maze[nx][ny] == '#')continue;
			if (maze[nx][ny] == '1') {
				cout << cnt + 1;
				return 0;
			}
			if (visited.find({ cbit,nx,ny }) != visited.end())continue;
			if (64 < maze[nx][ny] && maze[nx][ny] < 71) {
				if ((cbit & int(pow(2, maze[nx][ny] - 65))) > 0) {
					que.push({ { cbit,nx,ny }, cnt + 1 });
					visited.insert({ cbit,nx,ny });
				}
				continue;
			}
			if (96 < maze[nx][ny] && maze[nx][ny] < 103) {
				int nbit = cbit | int(pow(2, maze[nx][ny] - 97));
				que.push({ { nbit,nx,ny }, cnt + 1 });
				visited.insert({ nbit,nx,ny });
				continue;
			}
			que.push({{ cbit,nx,ny }, cnt + 1});
			visited.insert({ cbit,nx,ny });
		}
	}
	cout << "-1";
	return 0;
}