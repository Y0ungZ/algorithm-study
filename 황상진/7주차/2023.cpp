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
int N;

bool check(int num){
	for(int i=2;i*i<=num;i++){
		if(num%i==0) return false;
	}
	return true;
}

void dfs(int num, int index){
	if(index==N) cout<<num<<'\n';
	
	for(int i=1;i<=9;i+=2){
		int temp = num*10 + i;
		if(check(temp)){
			dfs(temp,index+1);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	
	cin>>N;
	
	int arr[4] = {2,3,5,7};
	
	for(int t : arr){
		dfs(t,1);
	}
	
	
	return 0;
}