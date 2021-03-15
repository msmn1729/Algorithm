#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iostream>
#include <climits>
#include <cstring>
#include <iomanip>
#include <bitset>
#include <string>
#include <vector>
#include <cmath>
#include <deque>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>

#define ll long long
#define INF 1e9

using namespace std;

//https://www.acmicpc.net/problem/11866 요세푸스 문제 0

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    deque<int> dq;
    int n, k;
    cin >> n >> k;
    for(int i=1; i<=n; i++) dq.push_back(i);
    cout << "<";
    
    while(dq.size()) {
        for(int i=0; i<k-1; i++) {
            int front = dq.front();
            dq.pop_front();
            dq.push_back(front);
        }
        cout << dq.front();
        dq.pop_front();
        if(dq.empty()) cout << ">";
        else cout << ", ";
    }
    
    return 0;
}
