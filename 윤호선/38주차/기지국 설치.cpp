#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    int x=1;
    
    for(int i=0;i<stations.size();i++){
        int y=stations[i]-w;
        int dis=y-x;
        
        if(y<0){
            x=stations[i]+w+1;
            continue;
        }
    
        if(dis>0){ 
            answer+=dis/(2*w+1);
            if(dis%(2*w+1)!=0)++answer;
        }
        x=stations[i]+w+1;
    }
    
    if(x<=n){
        answer+=(n-x+1)/(2*w+1);
        if((n-x+1)%(2*w+1)!=0)++answer;
    }
   

    return answer;
}