#include <string>
#include <vector>
#include <iostream>
using namespace std;
int cal(int sh,int sm, int eh, int em){
    if(em>sm) return (eh-sh)*60+(em-sm);
    return (eh-sh-1)*60+(em-sm)+60;
}
string solution(string m, vector<string> musicinfos) {
    string answer = "(None)";
    int max_time = -1;
    
    for(int i=0;i<musicinfos.size();i++){
        int sh=stoi(musicinfos[i].substr(0,2));
        int sm=stoi(musicinfos[i].substr(3,2));
        int eh=stoi(musicinfos[i].substr(6,2));
        int em=stoi(musicinfos[i].substr(9,2));
        int time=cal(sh,sm,eh,em);
        string title="";
        string lyrics="";
        
        int j=12;
        for(;j<musicinfos[i].size();j++){   
            if(musicinfos[i][j]==',')break;
            title.push_back(musicinfos[i][j]);
        }
        lyrics=musicinfos[i].substr(j+1);
        
        int plus=0;
        for(int t=0;t<time+plus;t++){
            if(lyrics[t%lyrics.size()]=='#')++plus;
        }
        if(lyrics[(time+plus)%lyrics.size()]=='#')++plus;
        
        for(int t=0;t<time+plus-(int)m.size()+1;t++){
            int cnt=t;
            bool flag=true;
            if(lyrics[cnt%lyrics.size()]=='#')continue;
            for(int k=0;k<m.size();k++){
                if(lyrics[cnt%lyrics.size()]!=m[k]){
                    flag=false;
                    break;
                }
                ++cnt;
            }
            if(lyrics[cnt%lyrics.size()]=='#')flag=false;
            if(flag){
                if(max_time<time){
                    answer=title;
                    max_time=time;
                }
                break;
            }
        }
    }
    return answer;
}