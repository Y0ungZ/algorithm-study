#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	priority_queue<int> pq;
	int N,ans = 0;

	cin >> N;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		pq.push(-1 * num);
	}
	
	while (pq.size()!=1) {
		int num1 = -1*pq.top();
		pq.pop();
		int num2 = -1*pq.top();
		pq.pop();

		ans += num1 + num2;
		pq.push(-1*(num1 + num2));
	}
	cout << ans;
	return 0;
}