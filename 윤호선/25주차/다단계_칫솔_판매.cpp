/*
    문제를 잘 읽자.
*/
#include <string>
#include <vector>
#include <map>
using namespace std;

map<string, int> member_num;
int cal(int num, int s, vector<string>& referral, vector<int>& answer){
    int p=s*0.1;
    answer[num]+=s;
    answer[num]-=p;
    if(referral[num]=="-")return 0;
    if(p==0)return 0;
    cal(member_num[referral[num]], p, referral, answer);
    return 0;
}
vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer(enroll.size());
    
    for(int i=0;i<enroll.size();i++){
        member_num.insert({enroll[i],i});
    }
    for(int i=0;i<seller.size();i++){    
        cal(member_num[seller[i]],amount[i]*100, referral, answer);
    }     
    return answer;
}