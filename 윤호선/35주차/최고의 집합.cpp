#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(int n, int s) {
    vector<int> False={-1};
    vector<int> answer;
    int num=s/n;
    int rest=s%n;
    
    if(num==0)return False;
    
    for(int i=0;i<n;i++){
        if(rest==0)answer.push_back(num);
        else{
            rest--;
            answer.push_back(num+1);
        }        
    }
    sort(answer.begin(),answer.end());
    return answer;
}