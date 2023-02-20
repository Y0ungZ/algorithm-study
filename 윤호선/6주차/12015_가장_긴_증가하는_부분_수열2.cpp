#include <iostream>
#include <vector>
using namespace std;

int binary_sol(vector<int>& res, int num, int start, int end) {
	int mid;
	while (start<=end) {
		mid = (start + end) / 2;
		if (res[mid] < num)start = mid + 1;
		else end = mid - 1;
	}
	res[start] = num;
	return 0;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, num;
	vector<int> res;

	cin >> n;
	cin >> num;
	res.push_back(num);

	for (int i = 1; i < n; i++) {
		cin >> num;
		if (res.back() < num)res.push_back(num);
		else binary_sol(res, num, 0, res.size() - 1);
	}
	cout << res.size();
	return 0;
}