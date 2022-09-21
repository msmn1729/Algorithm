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

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin >> t;
    int n;
    
    while(t--) {
        cin >> n;
        priority_queue<int> maxQ;
        priority_queue<int, vector<int>, greater<>> minQ;
        map<int, int> m;
        
        for(int i=0; i<n; i++) {
            string s;
            int num;
            cin >> s >> num;
            
            if(s == "I") {
                maxQ.push(num);
                minQ.push(num);
                m[num]++;
            }
            else if(s == "D" && num == 1) {
                while(maxQ.size() && !m[maxQ.top()]) {
                    maxQ.pop();
                }
                if(maxQ.empty()) continue;
                m[maxQ.top()]--;
                maxQ.pop();
            }
            else if(s == "D" && num == -1) {
                while(minQ.size() && !m[minQ.top()]) {
                    minQ.pop();
                }
                if(minQ.empty()) continue;
                m[minQ.top()]--;
                minQ.pop();
            }
        }
        
        // 큐에 실재하지 않는 값들 삭제
        while(maxQ.size() && !m[maxQ.top()]) {
            maxQ.pop();
        }
        while(minQ.size() && !m[minQ.top()]) {
            minQ.pop();
        }
        
        if(minQ.empty()) cout << "EMPTY\n";
        else cout << maxQ.top() << ' ' << minQ.top() << '\n';
    }
    
    return 0;
}
