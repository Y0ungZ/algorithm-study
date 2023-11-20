#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    int sum=0;
    
    sort(works.begin(),works.end());
    for(int i=0;i<works.size();i++){
        sum+=works[i];
    }
    sum-=n;
    
    if(sum<1)return 0;
    
    for(int i=0;i<works.size();i++){
        int num=sum/(works.size()-i);
        if(works[i]<num){
            answer+=works[i]*works[i];
            sum-=works[i];
        }
        else{
            answer+=num*num;
            sum-=num;
        }
    }
    return answer;
}