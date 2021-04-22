#include <string>
#include <vector>
#include <iostream>

using namespace std;

int visit[201];

void dfs(int n, vector<vector<int>>& computers, int cur) {
    visit[cur] = 1;
    for(int i=0; i<n; i++) {
        if(computers[cur][i] == 0 || cur == i) continue;
        int nxt = i;
        if(visit[nxt]) continue;
        dfs(n, computers, nxt);
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for(int i=0; i<n; i++) {
        if(visit[i]) continue;
        dfs(n, computers, i);
        answer++;
    }
    return answer;
}