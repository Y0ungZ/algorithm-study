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

int main() {
	int N,temp,total=0;
	bool available = false;
	vector<int> v;
	cin>>N;
	
	for(int i=0;i<N;i++){
		cin>>temp;
		v.push_back(temp);
		total+=temp;
	}
	
	if(total%3==0){
		int k = total/3;
		
		int cnt=0;
		
		for(int i=0;i<N;i++){
			cnt+=v[i]/2;
		}
		
		if(cnt>=k){
			available = true;
		}
	}
	
	cout<<(available? "YES": "NO");
	
	
	return 0;
}