/*
    size() 리턴값 size_t : long unsigned int(부호가 없는 4바이트 정수)
           시간 복잡도 O(1)
    length() 시간복잡도 O(N)
*/
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int cross(int num, int& k, vector<int>& stones){
    int cnt=0;
    for(int i=0;i<stones.size();i++){
        if(stones[i]<num)++cnt;
        else cnt=0;
        
        if(cnt==k)return 0;
    }
    return 1;
}
int bs(int start, int end,int& k, vector<int>& stones){
    int mid=0;
    
    while(start<=end){
        mid=(start+end)/2;
        
        if(cross(mid,k,stones))start=mid+1;
        else end=mid-1;
    }
    return end;
}
int solution(vector<int> stones, int k){
    return bs(1,*max_element(stones.begin(),stones.end()),k,stones);
}