#include <string>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> q;
    
    for(int i=0; i<progresses.size(); i++) {
        int tmp = ceil((100.0 - progresses[i]) / speeds[i]);
        q.push(tmp);
    }
    
    int day = 0;
    while(!q.empty()) {
        int cnt = 0;
        while(!q.empty() && q.front() <= day) {
            cnt++;
            q.pop();
        }
        if(cnt) answer.push_back(cnt);
        day++;
    }
    return answer;
}
