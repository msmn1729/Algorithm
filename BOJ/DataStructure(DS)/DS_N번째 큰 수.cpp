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
    
    int n;
    cin >> n;
    priority_queue<int, vector<int>, greater<>> pq;
    
    for(int i=0; i<n*n; i++) {
        int num;
        cin >> num;
        pq.push(num);
        if(pq.size() > n) pq.pop();
    }
    cout << pq.top();
    
    return 0;
}
