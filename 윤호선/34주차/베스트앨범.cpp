/*
    map의 시간복잡도 O(log N) 
    unordered_map의 시간복잡도 O(1)
*/
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

bool comp_genres(pair<string,int>& a,pair<string,int>& b){
    return a.second>b.second;
}
bool comp_plays(pair<int,int>& a,pair<int,int>& b){
    if(a.second==b.second)return a.first<b.first;
    return a.second>b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    vector<pair<string,int>> v_genres;
    unordered_map<string, int> m_genres;
    
    for(int i=0;i<genres.size();i++){
        m_genres[genres[i]]+=plays[i];
    }
    for(auto mg:m_genres){
        v_genres.emplace_back(mg);
    }
    sort(v_genres.begin(),v_genres.end(),comp_genres);
    
    for(auto vg:v_genres){
        vector<pair<int,int>> vec;
        for(int j=0;j<genres.size();j++){
            if(genres[j]==vg.first)vec.push_back({j,plays[j]});
        }
        sort(vec.begin(),vec.end(),comp_plays);
        
        answer.push_back(vec[0].first);
        if(vec.size()>1)answer.push_back(vec[1].first);
    }
    return answer;
}