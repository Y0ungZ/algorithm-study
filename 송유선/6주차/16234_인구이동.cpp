#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

void migration(int N, int x, int y, int L, int R, vector<vector<int>>& border, vector<vector<int>>& check)
{
	queue<pair<int, int>> q;

	q.push({ x,y });

	int sum = 0;
	int cnt = 0;
	while (!q.empty()) {
		int dx[] = { -1,0,1,0 };
		int dy[] = { 0,-1,0,1 };

		pair<int, int>coord = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = coord.first + dx[i], ny = coord.second + dy[i];
			if (nx < 0 || nx >= N || ny < 0 || ny >= N) {
				continue;
			}

			int gap = abs(border[coord.first][coord.second] - border[nx][ny]);
			if (check[nx][ny] == 0 && (gap >= L && gap <= R)) {
				q.push({ nx,ny });
				check[nx][ny] = 1;
				cnt++;
			}
		}
	}

	if (cnt != 0) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (check[i][j] == 1) {
					sum += border[i][j];
				}
			}
		}
		
		sum = sum / cnt;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (check[i][j] == 1) {
					border[i][j] = sum;
					check[i][j] = 2;
				}
			}
		}
	}

	return;
}

int main()
{
	int N, L, R;
	cin >> N >> L >> R;

	vector<vector<int>> border(N, vector<int>(N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> border[i][j];
		}
	}

	vector<vector<int>> check(N, vector<int>(N));
	int answer = 0;

	while (1) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (check[i][j] == 0) {
					migration(N, i, j, L, R, border, check);
				}
			}
		}

		int ch = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (check[i][j] != 0) {
					ch++;
				}
				check[i][j] = 0;
			}
		}

		if (ch) answer++;
		else break;
	}

	cout << answer << "\n";
	
	return 0;
}