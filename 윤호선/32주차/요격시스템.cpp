#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(const vector<int>& a, const vector<int>& b){
    if(a[0]==b[0])return a[1]<b[1];
    return a[0]<b[0];
}
int solution(vector<vector<int>> targets) {
    int answer = 1;
    
    sort(targets.begin(),targets.end(),comp);
    
    int y=targets[0][1];
    for(int i=1;i<targets.size();i++){
        if(targets[i][0]<y){
            if(targets[i][1]<y)y=targets[i][1];
        }
        else{
            answer++;
            y=targets[i][1];
        }
    }
    return answer;
}
