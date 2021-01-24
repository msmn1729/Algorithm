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

//https://www.acmicpc.net/problem/11286 절댓값 힙

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    priority_queue<pair<int, int> > pq;
    int n;
    cin >> n;
    while(n--) {
        int x;
        cin >> x;
        if(x) pq.push({-abs(x), -x});
        else {
            if(pq.empty()) cout << 0;
            else {
                cout << -pq.top().second;
                pq.pop();
            }
            cout << '\n';
        }
    }
    
    return 0;
}
