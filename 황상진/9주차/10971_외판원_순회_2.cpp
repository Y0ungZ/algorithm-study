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

#define INF 987654321;

int n, m[16][16];
int dp[16][1 << 16];

void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> m[i][j];
        }
    }

}

int DFS(int cur, int visit) {
    if (visit == (1 << n) - 1) {
        if (m[cur][0] == 0) {
            return INF;
        }
        return m[cur][0];
    }

    if (dp[cur][visit] != -1) {
        return dp[cur][visit];
    }
    dp[cur][visit] = INF;

    for (int i = 0; i < n; i++) {
        if (m[cur][i] == 0) continue;
        if ((visit & (1 << i)) != 0) continue;
        dp[cur][visit] = min(dp[cur][visit], m[cur][i] + DFS(i, visit | (1 << i)));
    }
    return dp[cur][visit];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    input();
    memset(dp, -1, sizeof(dp));
    cout<<DFS(0, 1);

    return 0;
}