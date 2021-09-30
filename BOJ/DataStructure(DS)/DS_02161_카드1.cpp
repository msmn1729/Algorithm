#include <iostream>
#include <cmath>
#include <queue>
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    
    deque<int> dq;
    for(int i=1; i<=n; i++) dq.push_back(i);
    
    while(dq.size()) {
        cout << dq.front() << ' ';
        dq.pop_front();
        int prev = dq.front();
        dq.pop_front();
        dq.push_back(prev);
    }
    
    return 0;
}
