#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int bfs(int c, vector<vector<int>>& path, vector<int>& visited) {
	queue<int> que;
	que.push(c);
	visited[c] = 1;

	while (!que.empty()) {
		int cur = que.front();
		que.pop();

		for (int j = 0; j < path[cur].size(); j++) {
			int next = path[cur][j];
			if (visited[next])continue;
			visited[next] = 1;
			que.push(next);
		}
	}
	return 0;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	string ans = "YES";
	int city_num, plan;
	cin >> city_num >> plan;

	//길로 이어진 도시 path에 기록
	vector<vector<int>> path(city_num + 1, vector<int>());
	for (int i = 0; i < city_num; i++) {
		for (int j = 0; j < city_num; j++) {
			int p;
			cin >> p;
			if (p)path[i + 1].push_back(j + 1);
		}
	}
	
	//여행 경로의 첫번째 도시 입력 받고 이 도시에서 갈 수 있는 모든 도시 찾기 
	int city;
	cin >> city;
	vector<int> visited(city_num + 1);
	bfs(city, path, visited);
	
	//여행 경로 중 갈 수 없는(위 bfs로 방문하지 않은) 도시를 입력 받으면 불가능 표시
	for (int i = 1; i < plan; i++) {
		cin >> city;
		if (visited[city] == 0) {
			ans = "NO";
			break;
		}
	}
	cout << ans;
	return 0;
}