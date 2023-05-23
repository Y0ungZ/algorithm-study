#include <string>
#include <vector>
using namespace std;

vector<vector<int>> table;
vector<int> answer;

void set(int r, int c){
    int num=0;
    for(int i=0;i<r;i++){
        vector<int> v;
        for(int j=0;j<c;j++){
            v.push_back(++num);
        }
        table.push_back(v);
    }
}
int rotate(int x,int y,int dx,int dy){
    int tmp=table[x][y];
    int min_val=tmp;
    for(int i=0;i<dy;i++){
        swap(tmp,table[x][++y]);
        if(min_val>tmp)min_val=tmp;
    }
    for(int i=0;i<dx;i++){
        swap(tmp,table[++x][y]);
        if(min_val>tmp)min_val=tmp;
    }
    for(int i=0;i<dy;i++){
        swap(tmp,table[x][--y]);
        if(min_val>tmp)min_val=tmp;
    }
    for(int i=0;i<dx;i++){
        swap(tmp,table[--x][y]);
        if(min_val>tmp)min_val=tmp;
    }
    answer.push_back(min_val);
    return 0;
}
vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    
    set(rows, columns);
    
    for(int i=0;i<queries.size();i++){
      rotate(queries[i][0]-1,queries[i][1]-1,queries[i][2]-queries[i][0],queries[i][3]-queries[i][1]);
    }
    return answer;
}