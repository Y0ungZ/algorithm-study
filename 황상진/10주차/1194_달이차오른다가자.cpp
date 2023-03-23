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
#include <bitset>

using namespace std;

int di[4] = { -1,0,1,0 };
int dj[4] = { 0,1,0,-1 };

int N, M;
vector<vector<char>>v(52, vector<char>(52));
bool visited[1 << 6][52][52];
int si, sj;
int res = -1;

struct qObject {
    int qi;
    int qj;
    int cnt;
    int key;
};

void input() {
    cin >> N >> M;
    char temp;

    for (int i = 0; i < N; i++)
    {
        string Inp; cin >> Inp;
        for (int j = 0; j < M; j++)
        {
            v[i][j] = Inp[j];
            if (v[i][j] == '0')
            {
                si = i;
                sj = j;
                v[i][j] = '.';
            }
        }
    }
}

void output() {
    cout << N << ' ' << M << '\n';

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << v[i][j] << ' ';
        }
        cout << '\n';
    }
}

void BFS() {
    queue<qObject> q;
    q.push(qObject{ si,sj,0,0 });
    visited[0][si][sj] = true;
    //output();

    while (!q.empty()) {
        auto t = q.front();
        int ti = t.qi;
        int tj = t.qj;
        int tcnt = t.cnt;
        int tkey = t.key;
        //cout << ti << ' ' << tj << ' ' << tcnt << ' ' << tkey << '\n';
        q.pop();

        for (int k = 0; k < 4; k++) {
            int ni = ti + di[k];
            int nj = tj + dj[k];

            if (ni < 0 || nj < 0 || ni >= N || nj >= M || visited[tkey][ni][nj] || v[ni][nj] == '#') continue;
            //cout << "다음" << ni << ' ' << nj << ' ' << v[ni][nj] << ' ' <<tkey<< '\n';
            if (v[ni][nj] >= 'a' && v[ni][nj] <= 'f') {
                int nkey = tkey | (1 << (v[ni][nj] - 97));
                q.push(qObject{ ni,nj,tcnt + 1,nkey });
                visited[nkey][ni][nj] = true;
            }
            else if (v[ni][nj] >= 'A' && v[ni][nj] <= 'F') {
                int temp = 1 << (v[ni][nj] - 65);
                if ((tkey & temp) == temp) {
                    q.push(qObject{ ni,nj,tcnt + 1,tkey });
                    visited[tkey][ni][nj] = true;
                }
            }
            else if (v[ni][nj] == '.') {
                q.push(qObject{ ni,nj,tcnt + 1,tkey });
                visited[tkey][ni][nj] = true;
            }
            else if (v[ni][nj] == '1') {
                res = tcnt + 1;
                break;
            }
        }
        if (res != -1) {
            break;
        }
    }
}

void solve() {
    BFS();
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    memset(visited, false, sizeof(visited));
    input();
    solve();
    cout << res;

    return 0;
}