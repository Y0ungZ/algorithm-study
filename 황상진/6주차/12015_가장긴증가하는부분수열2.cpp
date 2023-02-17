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

vector<int> v = {1000000};

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N;
  cin >> N;

  int e;

  for (int i = 0; i < N; i++)
  {
    cin >> e;

    if (e > v.back())
      v.push_back(e);
    else
    {
      int index = lower_bound(v.begin(), v.end(), e) - v.begin();
      v[index] = e;
    }
  }

  cout << v.size();

  return 0;
}