#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int binary_search(vector<int>& v,int i) {
	int s = 0, e = v.size() - 1;
	int mid;

	while (s <= e) {
		mid = (s + e) / 2;

		if (v[mid] < i)s = mid + 1;
		else e = mid - 1;
	}

	return s;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	vector<int> vec;
	map<long,vector<int>> m;
	int n, k, num, sum = 0;
	long cnt = 0;
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> num;
		sum += num;
		vec.push_back(sum);
		m[sum].push_back(i);
	}

	cnt += m[k].size();  //처음부터 i까지 누적합이 k인 경우
	for (int i = 0; i < n; i++) {
		long num = vec[i] - k;
		if (m.find(num) == m.end())continue;
		cnt += binary_search(m[num], i);	//cnt += lower_bound(m[num].begin(), m[num].end(), i) - m[num].begin();
	}

	cout << cnt;
	return 0;
}