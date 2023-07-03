#include <iostream>
using namespace std;

int dx[2] = { 1,0 };
int dy[2] = { 0,-1 };

int N;
char candy[4] = { 'C','P','Z','Y' };
char table[51][51] = { 0, };
int max_val = -1;

int counter(char c) {
	int cnt = 0;

	for (int j = 0; j < N; j++) {
		for (int k = 0; k < N; k++) {
			if (table[j][k] == c)cnt++;
			else {
				if (max_val < cnt)max_val = cnt;
				cnt = 0;
			}
		}
		if (max_val < cnt)max_val = cnt;
		cnt = 0;
	}
	for (int j = 0; j < N; j++) {
		for (int k = 0; k < N; k++) {
			if (table[k][j] == c)cnt++;
			else {
				if (max_val < cnt)max_val = cnt;
				cnt = 0;
			}
		}
		if (max_val < cnt)max_val = cnt;
		cnt = 0;
	}
	return 0;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> table[i][j];
		}
	}

	for (int i = 0; i < 4; i++) {
		counter(candy[i]);
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < 2; k++) {
				int x = i + dx[k];
				int y = j + dy[k];
				if (x < 0 || x >= N || y < 0 || y >= N)continue;
				if (table[i][j] == table[x][y])continue;
				swap(table[i][j], table[x][y]);
				counter(table[i][j]);
				counter(table[x][y]);
				swap(table[i][j], table[x][y]);
			}
		}
	}
	cout << max_val;
	return 0;
}