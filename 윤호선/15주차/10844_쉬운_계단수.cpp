#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n; cin >> n;
	int ans = 0;
	vector<int> vec = { 0,1,1,1,1,1,1,1,1,1 };
	
	while (--n) {
		vector<int> tmp(10);
		tmp[1] += vec[0];
		tmp[8] += vec[9];
		for (int i = 1; i < 9; i++) {
			tmp[i - 1] += vec[i];
			tmp[i + 1] += vec[i];
			tmp[i - 1] %= 1000000000;
		}
		tmp[8] %= 1000000000;
		tmp[9] %= 1000000000;
		vec = tmp;
	}
	for (int i = 0; i < 10; i++) {
		ans += vec[i];
		ans %= 1000000000;
	}
	cout << ans;
	return 0;
}