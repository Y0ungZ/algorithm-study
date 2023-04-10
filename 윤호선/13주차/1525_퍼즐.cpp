#include <iostream>
#include <string>
#include <map>
#include <queue>
using namespace std;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	char p;
	int start;
	string puzzle = "";
	map<string, int> visited;

	for (int i = 0; i < 9; i++) {
		cin >> p;
		puzzle.push_back(p);
		if (p == '0')start = i;
	}

	queue<pair<int, string>> que;
	que.push({ start,puzzle });
	visited[puzzle] = 0;

	while (!que.empty()) {
		int blank = que.front().first;
		int cx = blank / 3;
		int cy = blank % 3;
		string shape = que.front().second;
		que.pop();

		if (blank == 8 && shape == "123456780") {
			cout << visited[shape];
			return 0;
		}
		for (int i = 0; i < 4; i++) {
			int nblank;
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			string nshape = shape;
			
			if (nx < 0 || nx>2 || ny < 0 || ny>2)continue;

			nblank = nx * 3 + ny;
			swap(nshape[nblank], nshape[blank]);
			if (visited.find(nshape) != visited.end())continue;
			visited[nshape] = visited[shape] + 1;
			que.push({ nblank,nshape });
		}
	}
	cout << "-1";
	return 0;
}