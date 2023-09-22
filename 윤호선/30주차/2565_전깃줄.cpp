#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int binary_sol(vector<int>& vec, int num, int start, int end) {
	int mid;

	while (start <= end) {
		mid = (start + end) / 2;
		if (vec[mid] < num)start = mid + 1;
		else end = mid - 1;
	}
	vec[start] = num;
	return 0;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int N;cin >> N;
	vector<pair<int,int>> Line;
	vector<int> vec;

	for (int i = 0; i < N; i++) {
		int num1, num2;
		cin >> num1 >> num2;
		Line.push_back({ num1,num2 });
	}

	sort(Line.begin(), Line.end());

	vec.push_back(Line[0].second);
	for (int i = 1; i < N; i++) {
		if (vec.back() < Line[i].second)vec.push_back(Line[i].second);
		else binary_sol(vec, Line[i].second, 0, vec.size() - 1);
	}
	cout << N - vec.size();
	return 0;
}