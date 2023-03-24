#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> lecture_len;

bool check(int num) {
	int sum = 0, cnt = 0;
	for (int i = 0; i < lecture_len.size(); i++) {
		if (lecture_len[i] > num)return false;
		sum += lecture_len[i];
		if (sum <= num)continue;

		sum = lecture_len[i];
		cnt++;
	}
	cnt += 1;
	if (cnt > m)return false;
	return true;
}
int sol(int s, int e) {
	int mid;
	while (s <= e) {
		mid = (s + e) / 2;

		if (check(mid))e = mid - 1;
		else s = mid + 1;
	}
	return s;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

	int tmp, sum = 0;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> tmp;
		sum += tmp;
		lecture_len.push_back(tmp);
	}
	
	cout << sol(1, sum);
	return 0;
}