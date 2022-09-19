#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <map>
#include <sstream>
#include <cmath>
#include <cstring>
#include <stack>
#include <unordered_map>
#define ll long long
using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    int r = (int)arr1.size();
    int c = (int)arr2[0].size();
    answer.resize(r);
    
    for(int i=0; i<r; i++) {
        answer[i].resize(c);
        for(int j=0; j<c; j++) {
            // i, j로 좌표위치 잡음
            for(int k=0; k<arr2.size(); k++) {
                answer[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }
    
    return answer;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    solution({{1, 4}, {3, 2}, {4, 1}}, {{3, 3}, {3, 3}});
    
    return 0;
}
