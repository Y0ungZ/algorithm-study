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

struct todo
{
    int startTime;
    int endTime;
    int taken;
};


bool comp(const todo& a, const todo& b) {
    return a.endTime > b.endTime;
}



int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N;
    cin >> N;

    vector<todo> task(N);

    task[0] = { 0,0 };

    int t, s;
    for (int i = 0; i < N; i++) {
        cin >> t >> s;
        todo temp = { s - t,s,t };
        task[i] = temp;
    }

    sort(task.begin(), task.end(), comp);

    int time = task[0].endTime;
    for (auto t : task) {
        int s = t.startTime;
        int e = t.endTime;
        int takenTime = t.taken;
        
        if (e > time) {
            time -= takenTime;
        }
        else {
            time = s;
        }
        if (time < 0) {
            cout << -1;
            return 0;
        }
    }
    cout << time;



    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}