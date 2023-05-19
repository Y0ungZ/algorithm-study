#include <iostream>
#include <vector>
#include <math.h>
#include <queue>
using namespace std;

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int map_size;
vector<vector<int>> map;
vector<int> L;
int sum = 0, max_ice = 0;

void rotate(int p, int sx, int sy) {
	while (p > 0) {
		queue<int> que;
		int x = sx;
		int y = sy;

		for (int i = 0; i < 4; i++) {
			for (int j = 1; j < p; j++) {
				x += dx[i];
				y += dy[i];
				que.push(map[x][y]);
				if (i == 0)continue;
				map[x][y] = que.front();
				que.pop();
			}
		}
		for (int j = 1; j < p; j++) {
			x += dx[0];
			y += dy[0];
			map[x][y] = que.front();
			que.pop();
		}
		++sx;
		++sy;
		p -= 2;
	}
}
void melt() {
	vector<vector<int>> nmap(map_size, vector<int>(map_size));

	for (int i = 0; i < map_size; i++) {
		for (int j = 0; j < map_size; j++) {
			if (map[i][j] == 0)continue;
			int cnt = 0;
			for (int k = 0; k < 4; k++) {
				int nx = i + dx[k];
				int ny = j + dy[k];
				if (nx < 0 || nx >= map_size || ny < 0 || ny >= map_size)cnt++;
				else if (map[nx][ny] == 0)cnt++;
			}
			if (cnt > 1)nmap[i][j] = map[i][j] - 1;
			else nmap[i][j] = map[i][j];
		}
	}
	map = nmap;
}
void make_storm() {
	for (int l = 0; l < L.size(); l++) {
		int p = pow(2, L[l]);
		for (int i = 0; i < map_size; i += p) {
			for (int j = 0; j < map_size; j += p) {
				rotate(p, i, j);
			}
		}
		melt();
	}
}
void cal() {
	vector<vector<bool>> visited(map_size, vector<bool>(map_size));

	for (int i = 0; i < map_size; i++) {
		for (int j = 0; j < map_size; j++) {
			sum += map[i][j];
			if (map[i][j] == 0)continue;
			if (visited[i][j])continue;

			int ice = 0;
			queue<pair<int, int>> que;
			que.push({ i,j });
			visited[i][j] = true;

			while (!que.empty()) {
				int x = que.front().first;
				int y = que.front().second;
				que.pop();
				++ice;
				for (int k = 0; k < 4; k++) {
					int nx = x + dx[k];
					int ny = y + dy[k];
					if (nx < 0 || nx >= map_size || ny < 0 || ny >= map_size)continue;
					if (map[nx][ny] == 0)continue;
					if (visited[nx][ny])continue;
					visited[nx][ny] = true;
					que.push({ nx,ny });
				}
			}
			if (max_ice < ice)max_ice = ice;
		}
	}
}

int main() {
	int N, Q; cin >> N >> Q;
	map_size = pow(2, N);

	int input;
	for (int i = 0; i < map_size; i++) {
		vector<int> v;
		for (int j = 0; j < map_size; j++) {
			cin >> input;
			v.push_back(input);
		}
		map.push_back(v);
	}

	for (int i = 0; i < Q; i++) {
		cin >> input;
		L.push_back(input);
	}

	make_storm();
	cal();
	cout << sum << "\n" << max_ice;
	return 0;
}