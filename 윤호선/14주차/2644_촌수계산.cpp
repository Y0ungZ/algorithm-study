#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int person_num, per1, per2, num, child, parent;
	cin >> person_num >> per1 >> per2 >> num;

	vector<vector<int>> relationship(person_num+1, vector<int>());
	for (int i = 0; i < num; i++) {
		cin >> parent >> child;
		relationship[child].push_back(parent);
		relationship[parent].push_back(child);
	}

	queue<int> que;
	vector<int> visited(person_num + 1);
	que.push(per1);
	visited[per1] = 1;

	while (!que.empty()) {
		int cur = que.front();
		que.pop();

		for (int i = 0; i < relationship[cur].size(); i++) {
			int next = relationship[cur][i];
			if (next == per2) {
				cout << visited[cur];
				return 0;
			}
			if (visited[next] != 0)continue;
			que.push(next);
			visited[next] = visited[cur] + 1;
		}
	}

	cout << "-1";
	return 0;
}