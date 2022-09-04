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
#define ll long long
using namespace std;

int solution(string s) {
    int answer = (int)s.size();
    
    for(int i=1; i<=s.size()/2; i++) {
        string tok = "";
        vector<string> v;
        for(int j=0; j<s.size(); j++) {
            tok += s[j];
            if((j+1)%i == 0) {
                v.push_back(tok);
                tok = "";
            }
            else if(j == s.size() - 1) v.push_back(tok);
        }
        int cnt = 1;
        string newStr = "";
        for(int j=1; j<v.size(); j++) {
            if(v[j-1] == v[j]) {
                cnt++;
                continue;
            }
            if(cnt == 1) newStr += v[j-1];
            else newStr += to_string(cnt) + v[j-1];
            cnt = 1;
        }
        if(cnt > 1) newStr += to_string(cnt) + v.back();
        else newStr += v.back();
        answer = min(answer, (int)newStr.size());
    }
    
    return answer;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
//    solution("aabbaccc");
    solution("ababcdcdababcdcd");
    
    return 0;
}
