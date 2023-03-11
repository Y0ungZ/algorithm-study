#include <iostream>
#include <vector>
#include <set>
using namespace std;

int ans = 1000000000;
bool check(vector<int>& visited) {
	set<int> s;
	int cur = 0;

	while (s.find(cur) == s.end()) {
		s.insert(cur);
		cur = visited[cur] - 1;
	}
	if (s.size() == visited.size())return true;
	return false;
}
int sol(int sum, int cnt, int n, vector < vector<int>>& vec, vector<int>& visited) {
	if (cnt == n) {
		if (!check(visited))return 0;
		if (ans > sum)ans = sum;
		return 0;
	}
	
	for (int i = 0; i < n; i++) {
		if (vec[cnt][i] == 0)continue;
		if (visited[i] != 0)continue;

		visited[i] = cnt + 1;
		sol(sum + vec[cnt][i], cnt + 1, n, vec,visited);
		visited[i] = 0;
	}
	return 0;
}
int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

	int N;
	cin >> N;

	vector < vector<int>> vec(N,vector<int>(N));
	vector<int>visited(N);
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> vec[i][j];
		}
	}

	sol(0, 0, N, vec, visited);
	cout << ans;
	return 0;
}