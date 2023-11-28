#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> Weak;
vector<int> Dist;
vector<int> check;
vector<int> seq;
int N = 0;
int answer = -1;

int nextStart(int s, int e, int t){ //BinarySearch
    int mid;
    while(s<=e){
        mid=(s+e)/2;
        if(Weak[mid]<=t)s=mid+1;
        else e=mid-1;
    }
    return s;
}
bool isPossible(){
    for(int i=0;i<Weak.size();i++){
        int start=i;
        bool overN=false;
        for(int j=0;j<seq.size();j++){
            int range=Weak[start]+seq[j];
            start=nextStart(0,Weak.size()-1,range%N);
            
            if(range/N>1)return true;
            if(start<Weak.size()&&range<Weak.back()){
                if(overN&&i<=start)return true;
                continue;
            }
            
            start%=Weak.size();
            if(overN)return true;
            overN=true;
            if(overN&&i<=start)return true;
        }
    }
    return false; 
}
bool makeSeq(int num){
    if(seq.size()==num){
        if(isPossible()){
            answer=num;
            return true;
        }
        return false;
    }
    for(int i=0;i<num;i++){
        if(check[i]==1)continue;
        seq.push_back(Dist[i]);
        check[i]=1;
        if(makeSeq(num))return true;
        seq.pop_back();
        check[i]=0;
    }
    return false;
}
int solution(int n, vector<int> weak, vector<int> dist) {
    N=n;
    Weak=weak;
    Dist=dist;
    sort(Dist.begin(),Dist.end(),greater<>());
    check.assign(Dist.size(),0);
    
    for(int i=1;i<=Dist.size();i++){
        if(makeSeq(i))break;
    }
    return answer;
}