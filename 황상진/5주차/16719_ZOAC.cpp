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
int sLength;
string s;

void ZOAC(int level,vector<bool> v) {
	if (level == sLength) return;

	vector<string> tempArr;
	string res = "";
	int index = -1;

	for (int i = 0; i < sLength; i++) {
		if (v[i]) continue;
		else v[i] = true;
		string temp = "";
		for (int j = 0; j < sLength; j++) {
			if (v[j]) temp += s[j];
		}
		v[i] = false;
		
		if (res.length() == 0 || res > temp) {
			res = temp;
			index = i;
		}
	}
	
	v[index] = true;
	cout << res << '\n';
	ZOAC(level+1, v);
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> s;
	sLength = s.length();

	vector<bool> v(sLength, false);
	
	ZOAC(0,v);

	return 0;
}


