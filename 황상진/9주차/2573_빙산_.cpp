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

int di[4] = {-1,0,1,0};
int dj[4] = {0,1,0,-1}; 

int N,M;
vector<vector<int>> v;
bool visited[302][302];
int allgone = false;


void BFS(int x, int y){
    queue<pair<int,int>> q;
    visited[x][y] = true;
    q.push({x,y});
    
    while(!q.empty()){
        auto t= q.front();
        q.pop();
        int ti = t.first;
        int tj = t.second;
        
        for(int k=0;k<4;k++){
            int ni = ti+ di[k];
            int nj = tj + dj[k];

            if(ni<0 || nj<0 || ni>=N || nj>=M || visited[ni][nj] || !v[ni][nj]) continue;
            q.push({ni,nj});
            visited[ni][nj] = true;
        }
    }
}

bool checkDivided(){
    memset(visited,false, sizeof(visited));

    int cnt=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(!visited[i][j] && v[i][j]!=0) {
                cnt++;
                BFS(i,j);
                
            }
        }
    }
    if(cnt==0) {
        allgone = true;
        return true;
    }
    if(cnt>1) return true;
    return false;
}

void input(){
    cin>>N>>M;

    vector<int>tempVector;
    int temp;
    for(int i=0;i<N;i++){
        tempVector.clear();
        for(int j=0;j<M;j++){
            cin>>temp;
            tempVector.push_back(temp);
        }
        v.push_back(tempVector);
    }
    return;
}
void solve(){
    int yearCnt=1;

    while(951221){
        memset(visited,false, sizeof(visited));
        vector<pair<pair<int,int>,int>> reduceIce;

        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(!v[i][j]) continue;
                int aroundIceCnt=0;

                for(int k=0;k<4;k++){
                    int ni = i+di[k];
                    int nj = j + dj[k];
                    if(ni<0 || nj<0 || ni>=N || nj>=M || v[ni][nj]) continue;
                    aroundIceCnt++; 
                }
                if(aroundIceCnt){
                    reduceIce.push_back({{i,j},aroundIceCnt});
                }
            }
        }

        for(auto t: reduceIce){
            auto pos = t.first;
            int cnt = t.second;
            int ti = pos.first;
            int tj = pos.second;

            v[ti][tj] = (v[ti][tj]-cnt < 0)? 0 : v[ti][tj]-cnt;
        }

        if(checkDivided()){
            if(allgone){
                cout<<0;
                return;
            }
            cout<<yearCnt;
            break;
        }
        yearCnt++;
    }
}



int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);

    input();
    solve();

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}