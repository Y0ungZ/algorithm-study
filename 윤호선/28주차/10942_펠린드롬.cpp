#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	map<int, int> palin1;
	map<int, int> palin2;
	vector<int> numbers;
	int N, M;
	cin >> N;
	
	numbers.push_back(0);
	for (int n = 0; n < N; n++) {
		int num;
		cin >> num;
		numbers.push_back(num);
	}
	cin >> M;

	for (int n = 1; n <= N; n++) {
		int cnt = 0;
		while (1 <= n - cnt && n + cnt <= N) {
			if (numbers[n - cnt] != numbers[n + cnt])break;
			cnt++;
		}
		palin1.insert({ n, cnt - 1 });
		
		cnt = 1;
		while (1 <= n - cnt + 1 && n + cnt <= N) {
			if (numbers[n - cnt + 1] != numbers[n + cnt])break;
			cnt++;
		}
		palin2.insert({ n, cnt - 1 });
	}
	
	for (int m = 0; m < M; m++) {
		int n1, n2;
		cin >> n1 >> n2;

		if ((n1 + n2) % 2 == 0) {
			if (palin1[(n1 + n2) / 2] >= n2 - (n1 + n2) / 2)cout << true << "\n";
			else  cout << false << "\n";
		}
		else {
			if (palin2[(n1 + n2) / 2] >= n2 - (n1 + n2) / 2)cout << true << "\n";
			else  cout << false << "\n";
		}
	}
	return 0;
}