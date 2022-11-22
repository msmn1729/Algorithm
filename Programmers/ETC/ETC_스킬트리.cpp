#include <bits/stdc++.h>
using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    
    map<char, int> m;
    for(int i=0; i<skill.size(); i++) {
        m[skill[i]] = i+1;
    }
    
    for(string s : skill_trees) {
        int cnt = 0;
        int flag = 0;
        
        for(int i=0; i<s.size(); i++) {
            if(!m[s[i]]) continue;
            cnt++;
            if(cnt == m[s[i]]) continue;
            flag = 1;
            break;
        }
        if(!flag) answer++;
    }
    
    return answer;
}
