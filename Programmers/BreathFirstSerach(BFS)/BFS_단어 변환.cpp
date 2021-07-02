#include <bits/stdc++.h>
using namespace std;

int DiffCharCount(string s1, string s2) {
    int ret = 0;
    for(int i=0; i<s1.size(); i++) {
        if(s1[i] != s2[i]) ret++;
    }
    return ret;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    if(find(words.begin(), words.end(), target) == words.end()) return 0;
    
    queue<string> q;
    unordered_map<string, int> dist; // 문자와 거리를 저장
    for(string s : words) dist[s] = -1; // 미방문 처리
    dist[begin] = 0;
    q.push(begin);
    
    while(!q.empty()) {
        string cur = q.front(); q.pop();
        if(cur == target) return dist[cur]; // 정답 반환
        
        for(string nxt : words) {
            if(DiffCharCount(cur, nxt) > 1) continue;
            if(dist[nxt] > -1) continue;
            q.push(nxt);
            dist[nxt] = dist[cur] + 1;
        }
    }
    
    return answer;
}