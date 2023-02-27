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

int di[4] = {-1, 0, 1, 0};
int dj[4] = {0, 1, 0, -1};

int m[52][52];
int N, L, R;
bool visited[52][52];

vector<vector<pair<int, int>>> openBorderGroup;

void checkBorderopen(int i, int j)
{
  vector<pair<int, int>> res = {{i, j}};
  queue<pair<int, int>> q;
  q.push({i, j});
  visited[i][j] = true;

  while (!q.empty())
  {
    auto t = q.front();
    q.pop();
    int ti = t.first;
    int tj = t.second;

    for (int k = 0; k < 4; k++)
    {
      int ni = ti + di[k];
      int nj = tj + dj[k];

      if (ni < 0 || nj < 0 || ni >= N || nj >= N || visited[ni][nj])
        continue;

      int diff = abs(m[ni][nj] - m[ti][tj]);

      if (diff >= L && diff <= R)
      {
        res.push_back({ni, nj});
        visited[ni][nj] = true;
        q.push({ni, nj});
      }
    }
  }

  if (res.size() != 1)
    openBorderGroup.push_back(res);
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  cin >> L >> R;

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      cin >> m[i][j];
    }
  }
  int answer = 0;
  while (true)
  {

    for (int i = 0; i < N; i++)
    {
      memset(visited[i], false, sizeof(visited[i]));
    }

    for (int i = 0; i < N; i++)
    {
      for (int j = 0; j < N; j++)
      {
        if (!visited[i][j])
          checkBorderopen(i, j);
      }
    }

    if (openBorderGroup.size() == 0)
      break;
    else
    {
      for (auto t : openBorderGroup)
      {
        int total = 0;
        for (auto tt : t)
        {
          total += m[tt.first][tt.second];
        }
        for (auto tt : t)
        {
          m[tt.first][tt.second] = total / t.size();
        }
      }
    }
    answer++;
    openBorderGroup.clear();
  }
  cout << answer;

  return 0; // 정상종료시 반드시 0을 리턴해야합니다.
}