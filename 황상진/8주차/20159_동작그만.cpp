#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <cstring>
#include <string> 
#include <cmath>
#include <cstdio>
#include <set>
#include <map>
#include <sstream>

using namespace std;

int di[4] = { -1,0,1,0 };
int dj[4] = { 0,1,0,-1 };

/*6
3 2 5 2 1 3*/

long long psum[100002];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N,total=0;
    cin >> N;

    vector<int> card(N+1);
    vector<vector<int>> sum(2,vector<int>(N+1,0));

    for (int i = 0; i < N; i ++ ) {
        cin >> card[i];
    }


    int res = 0;
    int t;
    for (int i = 0; i < N; i++) {
        // 짝수일 경우 (zero base)
        if ((i + 1) % 2 == 0) sum[0][i / 2 + 1] = sum[0][i / 2] + card[i];
        // 홀수일 경우
        else sum[1][i / 2 + 1] = sum[1][i / 2] + card[i];
    }

    for (int i = 1; i <= N; i++) {
        int idx = i / 2 + 1;
        // 짝수일 경우
        if (i % 2 == 0) t = sum[1][idx - 1] + (sum[0][N / 2 - 1] - sum[0][idx - 2]);
        // 홀수일 경우
        else t= sum[1][idx - 1] + (sum[0][N / 2 - 1] - sum[0][idx - 1]) + card[N - 1];

        res = max(res, t);
    }
    cout << res;

    return 0;
}
