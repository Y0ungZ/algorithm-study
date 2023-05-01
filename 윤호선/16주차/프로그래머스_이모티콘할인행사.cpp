#include <string>
#include <vector>
using namespace std;

int dct[4]={40,30,20,10};
int max_pay=0,max_plus=-1;
vector<int> dcts;

int cal(vector<vector<int>>& users, vector<int>& emoticons){
    int plus_num=0;
    int total_pay=0;
    for(int i=0;i<users.size();i++){
        int user_dct=users[i][0];
        int pay=0;
        for(int j=0;j<emoticons.size();j++){
            if(user_dct<=dcts[j])pay+=emoticons[j]*(100-dcts[j])*0.01;
        }
        if(pay>=users[i][1])plus_num+=1;
        else total_pay+=pay;
    }
    if(plus_num>max_plus){
        max_plus=plus_num;
        max_pay=total_pay;
    }
    else if(plus_num==max_plus&&total_pay>max_pay)max_pay=total_pay;
    return 0;
}

int make_discount(vector<vector<int>>& users, vector<int>& emoticons){
    if(dcts.size()==emoticons.size()){
        cal(users,emoticons);
        return 0;
    }
    for(int i=0;i<4;i++){
        dcts.push_back(dct[i]);
        make_discount(users,emoticons);
        dcts.pop_back();
    }
    return 0;
}
vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer;
    make_discount(users,emoticons);
    answer={max_plus,max_pay};
    return answer;
}