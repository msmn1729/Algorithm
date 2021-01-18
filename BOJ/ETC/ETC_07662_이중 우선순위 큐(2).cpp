#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <string>
#include <map>
#include <iomanip>
#include <list>
#include <stack>
#include <cstring>
#include <cmath>
#include <set>
#include <unordered_map>
#include <bitset>
#define ll long long

using namespace std;

//https://www.acmicpc.net/problem/7662 이중 우선순위 큐

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t, n;
    cin >> t;
    
    while(t--) {
        priority_queue<int> maxQ;
        priority_queue<int, vector<int>, greater<> > minQ;
        unordered_map<int, int> m;
        
        cin >> n;
        while(n--) {
            char c;
            int in;
            cin >> c >> in;
            if(c == 'I') {
                maxQ.push(in);
                minQ.push(in);
                m[in]++;
            }
            else if(c == 'D') {
                if(in == 1) {
                    while(maxQ.size() && m[maxQ.top()] == 0) {
                        maxQ.pop();
                    }
                    if(maxQ.size()) {
                        m[maxQ.top()]--;
                        maxQ.pop();
                    }
                }
                else if(in == -1) {
                    while(minQ.size() && m[minQ.top()] == 0) {
                        minQ.pop();
                    }
                    if(minQ.size()) {
                        m[minQ.top()]--;
                        minQ.pop();
                    }
                }
            }
        }
        
        while(maxQ.size() && m[maxQ.top()] == 0) maxQ.pop();
        while(minQ.size() && m[minQ.top()] == 0) minQ.pop();
        if(minQ.size()) cout << maxQ.top() << ' ' << minQ.top();
        else cout << "EMPTY";
        cout << '\n';
    }
    return 0;
}
