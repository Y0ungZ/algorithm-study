#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <iostream>
using namespace std;

bool comp(vector<string>& a,vector<string>& b){
    return a[1]<b[1];
}
vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    stack<pair<string,int>> st;
    
    sort(plans.begin(),plans.end(),comp);
    
    for(vector<string>& plan :plans){
        int start_h=stoi(plan[1].substr(0,2));
        int start_m=stoi(plan[1].substr(3,2));
        plan[1]=to_string(start_h*60+start_m);
    }
   
    int p_end=stoi(plans[0][1])+stoi(plans[0][2]);
    
    for(int i=1;i<plans.size();i++){
        string c_name=plans[i][0];
        int c_start=stoi(plans[i][1]);
        int c_playtime=stoi(plans[i][2]);
        
        int interval=p_end-c_start;
        if(interval>0){
            st.push({plans[i-1][0],interval});
        }
        else{
            answer.push_back(plans[i-1][0]);
            interval*=-1;
            while(interval>0&&!st.empty()){
                if(interval-st.top().second>=0){
                    answer.push_back(st.top().first); 
                    interval-=st.top().second;
                    st.pop();
                }
                else{
                    st.top().second-=interval;
                    interval=0;
                }
            }
        }
        p_end=c_start+c_playtime;
    }
    answer.push_back(plans[plans.size()-1][0]);
    while(!st.empty()){
         answer.push_back(st.top().first); 
         st.pop();
    } 
    return answer;
}