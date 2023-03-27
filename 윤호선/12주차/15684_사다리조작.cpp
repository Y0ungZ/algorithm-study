#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, H, ans = 4;
int bridge[31][11] = { 0, };

bool check() {
	for (int i = 1; i <= N;i++) {
		int n = i;
		for (int j = 1; j <= H; j++) {
			if (bridge[j][n] == 1) n++;
			else if (bridge[j][n - 1] == 1)n--;
		}
		if (i != n)return false;
	}
	return true;
}

int make_bridge(int x,int y,int cnt) {
	if (cnt > 3)return 0;
	if (check()) {
		if (ans > cnt)ans = cnt;
		return 0;
	}

	if (y == N) {
		x++;
		y = 1;
	}
	for (int i = x; i <= H; i++) {
		for (int j = 1; j < N; j++) {
			if (i == x && j < y)continue;
			if (bridge[i][j] == 1)continue;
			if (bridge[i][j - 1] == 1||bridge[i][j+1]==1)continue;
			bridge[i][j] = 1;
			make_bridge(i, j + 1, cnt + 1);
			bridge[i][j] = 0;
		}
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int a, b;
	cin >> N >> M >> H;

	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		bridge[a][b] = 1;
	}
	make_bridge(1, 1, 0);
	if (ans == 4)cout << "-1";
	else cout << ans;
	return 0;
}