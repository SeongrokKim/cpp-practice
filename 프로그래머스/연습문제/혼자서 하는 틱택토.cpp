#include <string>
#include <vector>

using namespace std;
bool finish(vector<string> board, char type){
    if (board[0][0] == type && board[0][1] == board[0][0] && board[0][2] == board[0][1]){
        return true;
    }
    if (board[1][0] == type && board[1][1] == board[1][0] && board[1][2] == board[1][1]){
        return true;
    }
    if (board[2][0] == type && board[2][1] == board[2][0] && board[2][2] == board[2][1]){
        return true;
    }
    if (board[0][0] == type && board[1][0] == board[0][0] && board[2][0] == board[1][0]){
        return true;
    }
    if (board[0][1] == type && board[1][1] == board[0][1] && board[2][1] == board[1][1]){
        return true;
    }
    if (board[0][2] == type && board[1][2] == board[0][2] && board[2][2] == board[1][2]){
        return true;
    }
    if (board[0][0] == type && board[1][1] == board[0][0] && board[2][2] == board[1][1]){
        return true;
    }
    if (board[0][2] == type && board[1][1] == board[0][2] && board[2][0] == board[1][1]){
        return true;
    }
    return false;
}

int solution(vector<string> board) {
    int answer = 1;
    vector<pair<int, int>> o;
    vector<pair<int, int>> x;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(board[i][j]=='O'){
                o.push_back({i,j});
            }
            else if(board[i][j]=='X'){
                x.push_back({i,j});
            }
        }
    }
    // O가 X보다 2개 이상 많거나 X가 O보다 많을 경우
    if(o.size() > x.size()+1 || o.size() < x.size()){
        return 0;
    }
    // O가 끝났는데 X가 O보다 같거나 많은 경우
    if(finish(board, 'O')){
        if(x.size() >= o.size()){
            return 0;
        }
    }
    // X가 끝났는데 O가 X보다 많은 경우
    if(finish(board, 'X')){
        if(o.size()>x.size()){
            return 0;
        }
    }
    return answer;
}