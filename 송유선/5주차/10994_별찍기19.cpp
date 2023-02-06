#include <iostream>
#include <vector>
using namespace std;

int rc = 1;

void star(int n, vector<vector<int>> &check) {
	int ch = rc + (4 * n - 3) - 1;

	for (int i = rc; i <= ch; i++) {
		for (int j = rc; j <= ch; j++) {
			if (i == rc || j == rc || i == ch || j == ch) {
				check[i][j] = 1;
			}
		}
	}
	rc += 2;

	if (n - 1 > 0) {
		star(n - 1, check);
	}
	else {
		return;
	}
}

int main()
{
	int N;
	cin >> N;

	int ch = 4 * N - 3;
	vector<vector<int>> check(ch + 1, vector<int>(ch + 1));

	star(N, check);

	for (int i = 1; i <= ch; i++) {
		for (int j = 1; j <= ch; j++) {
			if (check[i][j] == 1) {
				cout << "*";
			}
			else {
				cout << " ";
			}
		}
		cout << "\n";
	}

	return 0;
}