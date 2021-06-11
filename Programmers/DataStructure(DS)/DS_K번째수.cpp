#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer, v;
    
    for(int i=0; i<commands.size(); i++) {
        v = array;
        sort(v.begin() + commands[i][0] - 1, v.begin() + commands[i][1]);
        answer.push_back(v[commands[i][0] + commands[i][2] - 2]);
    }
    
    return answer;
}
