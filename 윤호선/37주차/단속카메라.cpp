#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 1;
    sort(routes.begin(),routes.end());
    int y=routes[0][1];
    
    for(int i=1;i<routes.size();i++){
        int start=routes[i][0];
        int end=routes[i][1];
        
        if(y<start){
            ++answer;
            y=end;
        }
        else{
            if(end<y)y=end;
        }
    }
    
    return answer;
}