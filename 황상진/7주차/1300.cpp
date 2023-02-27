#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <cstring>
#include <string> 
#include <cmath>
#include <cstdio>
#include <set>
#include <map>
#include <sstream>

using namespace std;

int di[4] = {-1,0,1,0};
int dj[4] = {0,1,0,-1}; 

long long N,M;
int res =0;

long long getIndexFromMatrix(long long mid){
    long long res =0;

    for(int i=1;i<=N;i++){
        if(i >mid) break;
        res+=(N*i > mid)? (long long)mid/i : N;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);

    cin>>N>>M;

    long long low = 0;
    long long high = N*N;

    while(low<= high){
        long long mid = (low +high)/2;

        long long curIndex = getIndexFromMatrix(mid);
        if(curIndex < M) low = mid+1;
        else {
            res = mid;
            high = mid-1;
        }
    }
    cout<<res;

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}