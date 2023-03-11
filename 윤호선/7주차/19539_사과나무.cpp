#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, tree, sum = 0, cnt = 0;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> tree;
		sum += tree;
		cnt += tree / 2;
	}
	if (sum % 3 != 0)cout << "NO";
	else if (sum / 3 <= cnt)cout << "YES";
	else cout << "NO";

	return 0;
}
