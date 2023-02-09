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
#define MAX (10001)
#define INF (987654321)

int di[4] = {-1, 0, 1, 0};
int dj[4] = {0, 1, 0, -1};

using namespace std;

bool res = false;

void AtoB(string S, string T)
{
  if (S == T)
  {
    res = true;
    return;
  }
  else if (S.length() >= T.length())
    return;

  string temp = "";

  if (T[T.length() - 1] == 'A')
  {
    temp = T;
    temp.erase(temp.length() - 1);
    AtoB(S, temp);
  }
  if (T[0] == 'B')
  {
    temp = T;
    temp.erase(temp.begin());
    reverse(temp.begin(), temp.end());
    AtoB(S, temp);
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  string S, T;
  cin >> S >> T;

  AtoB(S, T);

  cout << (res) ? 1 : 0;

  return 0;
}
