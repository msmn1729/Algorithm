#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <map>
#include <sstream>
#define ll long long
using namespace std;

int solution(int n, vector<string> data) {
    int answer = 0;
    string combi = "ACFJMNRT";
    
    do {
        int flag = 0;
        for(string s : data) {
            int idx1 = (int)combi.find(s[0]);
            int idx2 = (int)combi.find(s[2]);
            char compare = s[3];
            int gap = s[4] - '0';
            int betweenFriends = abs(idx1 - idx2) - 1;
            if(compare == '=' && (betweenFriends != gap)) {
                flag = 1;
                break;
            }
            if(compare == '<' && (betweenFriends >= gap)) {
                flag = 1;
                break;
            }
            if(compare == '>' && (betweenFriends <= gap)) {
                flag = 1;
                break;
            }
        }
        if(flag) continue;
        answer++;
    } while(next_permutation(combi.begin(), combi.end()));
    
    return answer;
}

int main() {
    solution(2, {"N~F=0", "R~T>2"});

    return 0;
}
