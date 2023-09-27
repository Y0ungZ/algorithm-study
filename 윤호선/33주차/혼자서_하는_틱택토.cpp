#include <string>
#include <vector>

using namespace std;

int check(char ox,vector<string>& board){
    for(int i=0;i<3;i++){
        int cnt=0;
        for(int j=0;j<3;j++){
             if(board[i][j]==ox)cnt++;
        }
        if(cnt==3)return 1;
    }
    for(int i=0;i<3;i++){
        int cnt=0;
        for(int j=0;j<3;j++){
            if(board[j][i]==ox)cnt++;  
        }
        if(cnt==3)return 1;
    }
    if(board[0][0]==ox&&board[1][1]==ox&&board[2][2]==ox)return 1;
    if(board[0][2]==ox&&board[1][1]==ox&&board[2][0]==ox)return 1;
    return 0;  
}

int solution(vector<string> board) {
    int O_cnt=0,X_cnt=0;
    
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(board[i][j]=='O')O_cnt++;
            if(board[i][j]=='X')X_cnt++;
        }
    }
    
    int diff=O_cnt-X_cnt;
    if(diff==1){
        if(check('X',board))return 0;
        return 1;
    }
    else if(diff==0){
        if(check('O',board))return 0;
        return 1;
    }
    else return 0;
}