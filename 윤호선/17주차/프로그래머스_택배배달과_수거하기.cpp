#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    int cap_d=0,cap_p=0;
    
    for(int i=n-1;i>=0;i--){
        cap_d+=deliveries[i];
        cap_p+=pickups[i];
        
        if(cap_d<0)deliveries[i]=0;
        else{
            deliveries[i]=cap_d;
            cap_d=0;
        }
        if(cap_p<0)pickups[i]=0;
        else{
            pickups[i]=cap_p;
            cap_p=0;
        }
        
        int num=max(deliveries[i]/cap,pickups[i]/cap);
        answer+=2*(i+1)*num;
        deliveries[i]-=num*cap;
        pickups[i]-=num*cap;
        if(deliveries[i]>0||pickups[i]>0){
            answer+=2*(i+1);
            deliveries[i]-=cap;
            pickups[i]-=cap;
        }
        cap_d+=deliveries[i];
        cap_p+=pickups[i];
    }
    return answer;
}