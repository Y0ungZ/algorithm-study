#include <string>
#include <vector>
using namespace std;

string solution(int n, int m, int x, int y, int r, int c, int k) {
    int cnt=0, dx=x-r, dy=y-c, max_x=max(x,r), min_y=min(y,c);
    string path_rl="";
    vector<string> path(4,"");

    while(dx!=0||dy!=0){
        if(dx<0){
            path[0].push_back('d');
            dx++;
            cnt++;
        }
        if(dx>0){
            path[3].push_back('u');
            dx--;
            cnt++;
        }
        if(dy<0){
            path[2].push_back('r');
            dy++;
            cnt++;
        }
        if(dy>0){
            path[1].push_back('l');
            dy--;
            cnt++;
        }
    }
    if(k<cnt)return "impossible";
    if((k-cnt)%2)return "impossible";
    
    while(cnt<k){
        if(max_x<n){
            max_x++;
            path[0].push_back('d');
            path[3].push_back('u');  
        }
        else if(min_y>1){
            min_y--;
            path[1].push_back('l');
            path[2].push_back('r');
        }
        else path_rl+="rl";  
        cnt+=2;
    }
    return path[0]+path[1]+path_rl+path[2]+path[3];   
}