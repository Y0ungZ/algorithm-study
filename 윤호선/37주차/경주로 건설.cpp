#include <string>
#include <vector>
#include <queue>
using namespace std;

int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};

struct Pos{
    int x,y;
    int val;
    int dir;
};
bool operator<(const Pos& a, const Pos& b){
    return a.val>b.val;
}

int solution(vector<vector<int>> board) {
    
    vector<vector<int>>visited(board.size(),vector<int>(board.size()));
    priority_queue<Pos> pq;
    pq.push({0,0,0,-1});
    visited[0][0]=1;
    
    while(!pq.empty()){
        int cval=pq.top().val;
        int cdir=pq.top().dir;
        int cx=pq.top().x;
        int cy=pq.top().y;
        pq.pop();
        
        if(cx==board.size()-1&&cy==board.size()-1)return cval;
        if(visited[cx][cy]!=0&&visited[cx][cy]+400<cval)continue;
        visited[cx][cy]=cval;
        
        for(int i=0;i<4;i++){
            if(cdir!=-1&&i==(cdir+2)%4)continue;
            int nx=cx+dx[i];
            int ny=cy+dy[i];
            int nval=cval+100;
            
            if(nx<0||nx>=board.size()||ny<0||ny>=board.size())continue;
            if(board[nx][ny]==1)continue; 
            if(nx==0&&ny==0)continue;
            
            if(cdir!=-1&&cdir%2==1&&i%2==0)nval+=500;
            if(cdir!=-1&&cdir%2==0&&i%2==1)nval+=500;
            pq.push({nx,ny,nval,i});
        }
    }
    
    return -1;
}