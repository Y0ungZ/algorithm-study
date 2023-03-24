#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, w, L;
	cin >> n >> w >> L;

	vector<int> trucks(n);
	queue<int> que;
	int x = 0, y = 0, sum = 0, ans = 2 * w;

	for (int i = 0; i < n; i++) {
		cin >> trucks[i];

	}

	int j = 0;
	for (; j < min(n, w); j++) {
		if (sum + trucks[j] <= L) {
			sum += trucks[j];
			que.push(trucks[j]);
			continue;
		}
		break;
	}
	y = j - 1;
	
	if (y == n - 1) {
		cout << w + que.size();
		return 0;
	}

	while (que.size() < w) {
		que.push(0);
	}
	while (y < n - 1) {
		ans += 1;
		sum -= que.front();
		que.pop();
		if (sum + trucks[y + 1] > L) que.push(0);
		else {
			sum += trucks[y + 1];
			que.push(trucks[++y]);
		}
	}
	cout << ans;
	return 0;
}