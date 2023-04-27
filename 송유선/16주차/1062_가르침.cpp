#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<int> word(26);
int answer = 0;

void dfs(int s, int cnt, vector<string>& str, int K) {
	if (K == cnt) {
		int check = 0;
		for (int i = 0; i < str.size(); i++) {
			bool flag = true;
			for (int j = 4; j < str[i].length() - 4; j++) {
				if (!word[str[i][j] - 97]) {
					flag = false;
					break;
				}
			}
			if (flag) {
				check++;
			}
		}

		answer = max(answer, check);
		return;
	}
	for (int i = s; i < 26; i++) {
		if (!word[i]) {
			word[i] = 1;
			dfs(i, cnt + 1, str, K);
			word[i] = 0;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, K;
	cin >> N >> K;

	vector<string> str(N);
	for (int i = 0; i < N; i++) {
		cin >> str[i];
	}

	if (K < 5) {
		cout << "0\n";
		return 0;
	}
	else if (K == 26) {
		cout << N << "\n";
		return 0;
	}

	word[0] = 1;
	word[2] = 1;
	word[8] = 1;
	word[13] = 1;
	word[19] = 1;

	dfs(0, 0, str, K - 5);

	cout << answer << "\n";

	return 0;
}