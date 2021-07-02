#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> tickets;
vector<string> answer;
int max_depth;
int visited[10001];

void DFS(vector<string> tmp, string cur, int depth) {
    tmp.push_back(cur);
    if(max_depth < depth) {
        answer = tmp;
        max_depth = depth;
    }
    
    for(int i=0; i<tickets.size(); i++) {
        string st = tickets[i][0];
        string ed = tickets[i][1];
        if(visited[i]) continue;
        if(cur == st) {
            visited[i] = 1;
            DFS(tmp, ed, depth+1);
            visited[i] = 0;
        }
    }
}

vector<string> solution(vector<vector<string>> t) {
    vector<string> tmp;
    tickets = t;
    sort(tickets.begin(), tickets.end());
    DFS(tmp, "ICN", 0);
    
    return answer;
}