#include <string>
#include <vector>
#include <bitset>
#include <cmath>
using namespace std;

int isPossible(int s, int e, int prior, string& n){
    int mid=(s+e)/2;
    if(s>e)return 1;
    if(prior==0&&n[mid]=='1')return 0;
    return isPossible(s, mid-1, n[mid]-'0', n)&isPossible(mid+1, e, n[mid]-'0', n);
}
vector<int> solution(vector<long long> numbers) {
    vector<int> answer;
    
    for(auto num:numbers){
        string bitNum=bitset<63>(num).to_string();
        int bitNumSize=ceil(log2(num));
        if(bitNumSize==log2(num))++bitNumSize;
        int fullBinaryTreeSize=pow(2,(int)log2(bitNumSize)+1)-1;
        bitNum=bitNum.substr(bitNum.size()-fullBinaryTreeSize);
        answer.push_back(isPossible(0,bitNum.size()-1,1,bitNum));
    }
    return answer;
}