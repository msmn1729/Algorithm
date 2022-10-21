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
#include <set>
#define ll long long
#define INF 1e9
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    
    vector<pair<int, int> > v;
    
    deque<pair<int, int> > dq;
    for(int i=0; i<priorities.size(); i++) {
        dq.push_back({i, priorities[i]});
    }
    
    while(dq.size()) {
        int idx = dq.front().first;
        int cur = dq.front().second;
        int flag = 0;
        
        for(int i=1; i<dq.size(); i++) {
            if(cur < dq[i].second) {
                flag = 1;
                break;
            }
        }
        
        dq.pop_front();
        if(flag) {
            dq.push_back({idx, cur});
        }
        else {
            answer++;
            if(idx == location) break;
        }
    }
    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cout << solution({2, 1, 3, 2}, 2);
    
    return 0;
}
