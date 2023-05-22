#include <string>
#include <map>
#include <algorithm>
using namespace std;

void make_mapping(map<string,int>& m,string& str){
    for(int i=0;i<str.length();i++){
        str[i]=tolower(str[i]);
        
        if(i==0)continue;
        if(str[i-1]<97||str[i-1]>122)continue;
        if(str[i]<97||str[i]>122)continue;
        m[str.substr(i-1,2)]++;
    }
}
int solution(string str1, string str2) {
    int u=0, is=0;
    map<string,int> m1,m2;
    
    make_mapping(m1,str1);
    make_mapping(m2,str2);
    
    if(m1.size()==0&&m2.size()==0)return 65536;
  
    map<string,int>::iterator it;
    for(it=m1.begin();it!=m1.end();it++){
        if(m2.find(it->first)!=m2.end()){
            u+=max(it->second,m2[it->first]);
            is+=min(it->second,m2[it->first]);
        }
        else u+=it->second;
    }
    
    for(it=m2.begin();it!=m2.end();it++){
        if(m1.find(it->first)==m1.end())u+=it->second;     
    }
    
    return is*65536/u;
}