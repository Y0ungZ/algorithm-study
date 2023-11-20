#include <string>
#include <vector>
#include <queue>
using namespace std;

struct Cost{
    int x,y;
    int val;
};
bool operator<(const Cost& a,const Cost& b){
        return a.val>b.val;
}
/*  
    struct comp{
        bool operator()(Cost a, Cost b){
            return a.val>b.val;
        }
    };  
    
    선언 : priority_queue<Cost,vector<Cost>,comp> pq;
*/
vector<int> parents;
int Find(int a){
    if(parents[a]==a)return a;
    return Find(parents[a]);
}
int Union(int a,int b){
    a=Find(a);
    b=Find(b);
    return parents[b]=a;
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0; 
    priority_queue<Cost> pq;

    //parents 초기화
    for(int i=0;i<n;i++){
        parents.push_back(i);
    }
    for(int i=0;i<costs.size();i++){
        pq.push({costs[i][0],costs[i][1],costs[i][2]});
    }
    
    while(!pq.empty()){
        Cost cur=pq.top();
        pq.pop();
        
        if(Find(cur.x)==Find(cur.y))continue;
        Union(cur.x,cur.y);
        answer+=cur.val;
    }

    /*
    vector<int> visited(n);
    vector<vector<int>> dist(n,vector<int>(n));
    priority_queue<pair<int,int>> pq;
    
    for(int i=0;i<costs.size();i++){
        dist[costs[i][0]][costs[i][1]]=costs[i][2];
        dist[costs[i][1]][costs[i][0]]=costs[i][2];
    }
    pq.push({0,0});
    while(!pq.empty()){
        int val = -pq.top().first;
        int e = pq.top().second;
        pq.pop();
        
        if(visited[e]==1)continue;
        
        visited[e]=1;   
        for(int i=0;i<dist[e].size();i++){
            if(dist[e][i]==0)continue;
            pq.push({-dist[e][i],i});
        }
        answer+=val;
    }
    */
    return answer;
}