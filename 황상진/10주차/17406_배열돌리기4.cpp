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

struct rotationObject {
    int r;
    int c;
    int s;
};

int N, M, K;
int res = -1;
vector<vector<int>> v(52,vector<int>(52,0));
vector<rotationObject>rotationArr;

void input() {
    cin >> N >> M >> K;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> v[i][j];
        }
    }

    int r, c, s;
    for (int i = 0; i < K; i++) {
        cin >> r >> c >> s;
        rotationArr.push_back(rotationObject{ r,c,s });
    }
}

void output() {
    cout << N << ' ' << M << ' ' << K << '\n';
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cout << v[i][j] << ' ';
        }
        cout << '\n';
    }
    for (int i = 0; i < K; i++) {
        auto t = rotationArr[i];
        cout << t.r << ' ' << t.c << ' ' << t.s << '\n';
    }
}

int checkMin(vector<vector<int>> temp) {
    int tempRes = -1;

    for (int i = 1; i <= N; i++) {
        int t = 0;
        for (int j = 1; j <= M; j++) {
            t += temp[i][j];
        }
        
        tempRes = (tempRes == -1 || tempRes > t) ? t : tempRes;
    }
    return tempRes;
}

vector<vector<int>> rotation(vector<vector<int>> temp, rotationObject RO) {
    int R = RO.r;
    int C = RO.c;
    int S = RO.s;
    
    vector<vector<int>> newTemp = temp;

    for (int d = 1; d <= S; d++) {
        for (int j = C - d; j < C + d; j++) {
            newTemp[R - d][j + 1] = temp[R - d][j];
        }
        for (int i = R - d; i < R + d; i++) {
            newTemp[i + 1][C + d] = temp[i][C + d];
        }
        for (int j = C + d; j > C - d; j--) {
            newTemp[R + d][j - 1] = temp[R + d][j];
        }

        for (int i = R + d; i > R - d; i--) {
            newTemp[i - 1][C - d] = temp[i][C - d];
        }
    }
    return newTemp;

}

void DFS(vector<vector<int>> temp, int index, vector<bool> visited) {
    if (index == K) {
        int count = checkMin(temp);
        if (res == -1 || count < res) res = count;
        return;
    }

    for (int i = 0; i < K; i++) {
        if (visited[i]) continue;

        visited[i] = true;
        vector<vector<int>> nextTemp = rotation(temp, rotationArr[i]);
        DFS(nextTemp, index + 1, visited);
        visited[i] = false;
    }
}

void solve() {
    vector<bool> visited(K,false);
    DFS(v, 0,visited);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    input();
    solve();

    cout << res;

    return 0;
}