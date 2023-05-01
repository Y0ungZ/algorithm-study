#include <iostream>
#include <vector>
#include <string>
using namespace std;

int ans = 0;
vector<int> alpa(26);
vector<string> words;

int choose_alpabet(int s, int cnt) {
	if (cnt == 0) {
		int num = 0;
		for (int i = 0; i < words.size(); i++) {
			string word = words[i];
			bool flag = true;
			for (int j = 4; j < word.length() - 4; j++) {
				if (alpa[word[j] - 97] != 1) {
					flag = false;
					break;
				}
			}
			if (!flag)continue;
			num++;
		}
		if (ans < num)ans = num;
		return 0;
	}
	for (int i = s; i < 26; i++) {
		if (i == 0 || i == 2 || i == 8 || i == 13 || i == 19)continue;
		alpa[i] = 1;
		choose_alpabet(i + 1, cnt - 1);
		alpa[i] = 0;
	}
	return 0;
}
int main() {
	int N, K;
	cin >> N >> K;
	
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		words.push_back(str);
	}

	if (K < 5) {
		cout << ans;
		return 0;
	}

	alpa[0] = 1;
	alpa[2] = 1;
	alpa[8] = 1;
	alpa[13] = 1;
	alpa[19] = 1;

	choose_alpabet(1, K - 5);
	cout << ans;
	return 0;
}