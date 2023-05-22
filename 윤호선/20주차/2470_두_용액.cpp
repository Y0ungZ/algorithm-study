#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int num1, num2, min_val = 2000000001;

int sol(int num, int s,int e, vector<int>& vec) {
	int mid;
	while (s <= e) {
		mid = (s + e) / 2;
		if (num + vec[mid] == 0)return mid;
		if (num + vec[mid] < 0)s = mid + 1;
		else e = mid - 1;
	}
	return s;
}
int comp(int a, int b, vector<int>& vec) {
	if (b == vec.size())return 0;
	if (min_val > abs(vec[a] + vec[b])) {
		num1 = vec[a];
		num2 = vec[b];
		min_val = abs(vec[a] + vec[b]);
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	vector<int> vec(n);

	for (int i = 0; i < n; i++) {
		cin >> vec[i];
	}

	sort(vec.begin(), vec.end());

	for (int i = 0; i < n; i++) {
		int idx = sol(vec[i], 0, n - 1, vec);
		if (idx != 0 && idx - 1 != i) comp(i, idx - 1, vec);
		if (i != idx)comp(i, idx, vec);
	}
	cout << min(num1, num2) << " " << max(num1, num2);
	return 0;
}