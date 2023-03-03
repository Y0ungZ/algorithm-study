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

int di[4] = { -1,0,1,0 };
int dj[4] = { 0,1,0,-1 };

using namespace std;

long long psum[200002];
map<long long, long long> m;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	long long N, K;
	cin >> N >> K;

	for (long long i = 1; i <= N; i++) {
		long long temp;
		cin >> temp;
		psum[i] = psum[i - 1] + temp;
	}

	long long res = 0;

	for (long long i = 1; i <= N; i++) {
		if (psum[i] == K) res++;
		res += m[psum[i] - K];
		m[psum[i]]++;
	}
	cout << res;

	return 0;
}


