#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int answer = 250001;

void rotate(int r, int c, int s, vector<vector<int>> &arr) {
	int cnt = s;
	int row_p = r + s, row_m = r - s, col_p = c + s, col_m = c - s;

	while (cnt != 0) {
		queue<int> q;
		for (int j = row_m; j <= row_p; j++) {
			q.push(arr[j][col_m]);
		}
		for (int j = col_m + 1; j <= col_p; j++) {
			q.push(arr[row_p][j]);
		}
		for (int j = row_p - 1; j >= row_m; j--) {
			q.push(arr[j][col_p]);
		}
		for (int j = col_p - 1; j >= col_m + 1; j--) {
			q.push(arr[row_m][j]);
		}

		int tmp = q.front();
		q.pop();
		q.push(tmp);

		for (int j = row_m; j <= row_p; j++) {
			arr[j][col_m] = q.front();
			q.pop();
		}
		for (int j = col_m + 1; j <= col_p; j++) {
			arr[row_p][j] = q.front();
			q.pop();
		}
		for (int j = row_p - 1; j >= row_m; j--) {
			arr[j][col_p] = q.front();
			q.pop();
		}
		for (int j = col_p - 1; j >= col_m + 1; j--) {
			arr[row_m][j] = q.front();
			q.pop();
		}
		cnt--;
		row_p--;
		row_m++;
		col_p--;
		col_m++;
	}
}

int cal(int N, int M, vector<vector<int>> &arr) {
	for (int i = 1; i <= N; i++) {
		int sum = 0;
		for (int j = 1; j <= M; j++) {
			sum += arr[i][j];
		}
		answer = min(answer, sum);
	}

	return answer;
}

int main()
{
	int N, M, K;
	cin >> N >> M >> K;

	vector<vector<int>> arr(N + 1, vector<int>(M + 1));
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> arr[i][j];
		}
	}

	vector<vector<int>> v(K, vector<int>(3));
	for (int i = 0; i < K; i++) {
		cin >> v[i][0] >> v[i][1] >> v[i][2];		
	}

	vector<int> order(K);
	for (int i = 0; i < K; i++) {
		order[i] = i;
	}

	do {
		vector<vector<int>> change(N + 1, vector<int>(M + 1));
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				change[i][j] = arr[i][j];
			}
		}
		for (int i = 0; i < order.size(); i++) {
			rotate(v[order[i]][0], v[order[i]][1], v[order[i]][2], change);
		}
		answer = cal(N, M, change);
	} while (next_permutation(order.begin(), order.end()));

	cout << answer << "\n";

	return 0;
}