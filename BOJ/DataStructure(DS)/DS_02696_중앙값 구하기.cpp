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

    int t, m;
    cin >> t;
    while(t--) {
        cin >> m;
        cout << (m + 1) / 2 << '\n';
        priority_queue<int> maxHeap;
        priority_queue<int, vector<int>, greater<>> minHeap;
        
        for(int i=1; i<=m; i++) {
            int num;
            cin >> num;
            // 홀수 번째
            if(maxHeap.size() == minHeap.size()) {
                maxHeap.push(num);
            }
            // 짝수 번째
            else {
                minHeap.push(num);
            }
            
            // 힙의 top swap
            if((maxHeap.size() && minHeap.size()) && (maxHeap.top() > minHeap.top())) {
                int mx = maxHeap.top();
                int mn = minHeap.top();
                swap(mx, mn);
                maxHeap.pop(); maxHeap.push(mx);
                minHeap.pop(); minHeap.push(mn);
            }
            if(i % 2) cout << maxHeap.top() << ' ';
            if(i % 20 == 0) cout << '\n';
        }
        cout << "\n";
    }
    
    return 0;
}
