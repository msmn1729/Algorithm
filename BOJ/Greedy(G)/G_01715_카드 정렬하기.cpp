#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    priority_queue<int, vector<int>, greater<>> pq;
    
    for(int i=0; i<n; i++) {
        int num;
        cin >> num;
        pq.push(num);
    }
    
    int ans = 0;
    while(pq.size()) {
        int a = pq.top();
        pq.pop();
        if(pq.empty()) continue;
        int b = pq.top();
        pq.pop();
        pq.push(a + b);
        ans += (a + b);
    }
    
    cout << ans;
    
    return 0;
}
