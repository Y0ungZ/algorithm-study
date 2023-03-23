

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

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    string s;
    cin >> s;


    int Pcnt = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'P') {
            Pcnt++;
        }
        else {
            if (Pcnt >= 2 && s[i + 1] == 'P') {
                Pcnt--;
                i++;
            }
            else {
                cout << "NP";
                return 0;
            }
        }
    }
    if (Pcnt == 1) cout << "PPAP";
    else cout << "NP";

    return 0;
}