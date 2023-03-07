#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

int arr[50][50] = { 0, };
int commend[6][3] = { 0, };
int ans = 50000;

int find_min_val(int n,int m, int tmp_arr[50][50]) {
	for (int i = 0; i< n; i++) {
		int sum = 0;
		for (int j = 0; j < m; j++) {
			sum += tmp_arr[i][j];
		}
		if (sum < ans)ans = sum;
	}
	return 0;
}

int rotate(int n, int m, vector<int>& seq) {
	int tmp_arr[50][50];
	copy(&arr[0][0], &arr[0][0] + 2500, &tmp_arr[0][0]);
	
	for (int s : seq) {
		for (int i = 1; i <= commend[s][2]; i++) {
			int cur_x = commend[s][0] - i - 1;
			int cur_y = commend[s][1] - i - 1;
			int tmp_val= tmp_arr[cur_x][cur_y];

			for (int j = 0; j < 4; j++) {
				int num = 2 * i;
				while (num--) {
					cur_x += dx[j];
					cur_y += dy[j];
					swap(tmp_arr[cur_x][cur_y], tmp_val);
				}
			}		
		}
	}
	find_min_val(n, m,tmp_arr);
	return 0;
}
int make_seq(int n, int m, vector<int>& seq) {
	do {
		rotate(n,m,seq);
	} while (next_permutation(seq.begin(), seq.end()));
	return 0;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

	vector<int> S;
	int N, M, K;
	cin >> N >> M >> K;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}
	
	for (int i = 0; i < K; i++) {
		S.push_back(i);
		cin >> commend[i][0] >> commend[i][1] >> commend[i][2];
	}

	make_seq(N, M, S);
	cout << ans;
	return 0;
}