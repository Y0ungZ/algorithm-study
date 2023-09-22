#include iostream
using namespace std;

int main() {
	ios_basesync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int map[101][101] = { 0, };
	int N, L;
	cin  N  L;
	
	int ans = 2  N;
	for (int i = 0; i  N; i++) 
		for (int j = 0; j  N; j++)
			cin  map[i][j];

	for (int i = 0; i  N; i++) {
		int pre = map[i][0];
		int cnt = 1;
		int ramp = false;
		for (int j = 1; j  N; j++) {
			int dif = map[i][j] - pre;

			if (ramp && cnt == L) {		내려오는 경사로를 완성하면
				cnt = 0;
				ramp = false;
			}
			if (dif == 0) {
				++cnt;
				continue;
			}
			if (ramp) {		내려오는 경사로를 만들어야하는데 경사가 다르면
				--ans;
				ramp = false;
				break;
			}
			if (abs(dif)  1) {		경사 차가 1 이상이면
				--ans;
				break;
			}

			if (dif  0) {		전의 길보다 지금의 길이 높으면
				if (cnt = L) {
					cnt = 1;
					pre = map[i][j];
				}
				else {
					--ans;
					break;
				}
			}
			if (dif  0) {	전의 길보다 지금의 길이 낮으면
				cnt = 1;
				pre = map[i][j];
				ramp = true;
			}
		}
		if (ramp && cnt  L) --ans;		내려오는 경사로 완성 못하면
	}
	for (int i = 0; i  N; i++) {
		int pre = map[0][i];
		int cnt = 1;
		int ramp = false;
		for (int j = 1; j  N; j++) {
			int dif = map[j][i] - pre;

			if (ramp && cnt == L) {		내려오는 경사로를 완성하면
				cnt = 0;
				ramp = false;
			}
			if (dif == 0) {
				++cnt;
				continue;
			}
			if (ramp) {		내려오는 경사로를 만들어야하는데 경사가 다르면
				--ans;
				ramp = false;
				break;
			}
			if (abs(dif)  1) {		경사 차가 1 이상이면
				--ans;
				break;
			}

			if (dif  0) {	전의 길보다 지금의 길이 높으면
				if (cnt = L) {
					cnt = 1;
					pre = map[j][i];
				}
				else {
					--ans;
					break;
				}
			}
			if (dif  0) {	전의 길보다 지금의 길이 낮으면
				cnt = 1;
				pre = map[j][i];
				ramp = true;
			}
		}
		if (ramp && cnt  L) --ans;		내려오는 경사로 완성 못하면
	}
	cout  ans;
	return 0;
}