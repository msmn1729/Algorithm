#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> stk;
    
    for(int i=0; i<moves.size(); i++) {
        int target_line = moves[i] - 1;
        
        for(int row=0; row<board.size(); row++) {
            int& target_doll = board[row][target_line];
            if(target_doll == 0) continue;
            if(stk.size() && stk.top() == target_doll) {
                answer += 2;
                stk.pop();
            }
            else stk.push(target_doll);
            target_doll = 0;
            break;
        }
    }
    return answer;
}