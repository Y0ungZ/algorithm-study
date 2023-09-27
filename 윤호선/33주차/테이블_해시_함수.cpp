#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int Col=0;
bool comp(vector<int>& a, vector<int>& b){
    if(a[Col-1]==b[Col-1])return a[0]>b[0];
    return a[Col-1]<b[Col-1];
}

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    int answer = 0;
    Col=col;
    sort(data.begin(),data.end(),comp);

    for(int i=row_begin-1;i<=row_end-1;i++){
        int S=0;
        for(int j=0;j<data[i].size();j++){
            S+=data[i][j]%(i+1);
        }
        answer^=S;
    }
    return answer;
}