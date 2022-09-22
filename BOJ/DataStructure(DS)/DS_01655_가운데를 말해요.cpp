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
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    priority_queue<int> maxQ;
    priority_queue<int, vector<int>, greater<>> minQ;
    
    for(int i=0; i<n; i++) {
        int in;
        cin >> in;
        
        if(maxQ.size() == minQ.size()) {
            maxQ.push(in);
        }
        else {
            minQ.push(in);
        }
        
        if((maxQ.top() > minQ.top())) {
            int mx = maxQ.top();
            int mn = minQ.top();
            swap(mx, mn);
            maxQ.pop(); maxQ.push(mx);
            minQ.pop(); minQ.push(mn);
        }
        cout << maxQ.top() << '\n';
    }
    
    return 0;
}
