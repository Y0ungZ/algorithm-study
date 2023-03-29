#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct ShortCut
{
	int x;
	int y;
	int val;
};

bool compare(const ShortCut& sc1, const ShortCut& sc2) {
	if (sc1.x == sc2.x) {
		if (sc1.y == sc2.y) {
			return sc1.val < sc2.val;
		}
		return sc1.y < sc2.y;
	}
	return sc1.x < sc2.x;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int N, D, input_x, input_y, input_val, ans;
	cin >> N >> D;

	vector<ShortCut> sc;
	sc.push_back({ 0,0,0 });
	for (int i = 0; i < N; i++) {
		cin >> input_x >> input_y >> input_val;
		if (input_y > D)continue;
		sc.push_back({ input_x,input_y,input_val });
	}

	sort(sc.begin(), sc.end(), compare);

	vector<vector<int>> dp(3, vector<int>(sc.size()));
	for (int i = 1; i < sc.size(); i++) {
		int j = i;
		dp[0][i] = sc[i].val + sc[i].x;
		dp[1][i] = sc[i].y;
		while (--j) {
			if (sc[i].y < sc[j].y)continue;
			dp[1][i] = min(dp[2][j] + sc[i].y - sc[j].y, dp[1][i]);
			if (sc[i].x < sc[j].y)continue;
			dp[0][i] = min(dp[2][j] + sc[i].x - sc[j].y + sc[i].val, dp[0][i]);
		}
		dp[2][i] = min(dp[0][i], dp[1][i]);
	}

	ans = D;
	for (int i = 1; i < sc.size(); i++) {
		ans = min(dp[2][i] + D - sc[i].y, ans);
	}
	cout << ans;
	return 0;
}