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

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    ll answer = 0;
    int n, k;
    cin >> n >> k;
    vector<pair<int, int> > jewel(n);
    vector<int> bag(k);
    
    for(int i=0; i<n; i++) cin >> jewel[i].first >> jewel[i].second;
    
    for(int i=0; i<k; i++) cin >> bag[i];
    
    sort(jewel.begin(), jewel.end());
    sort(bag.begin(), bag.end());
    
    priority_queue<int> pq;
    int idx = 0;
    
    for(int i=0; i<k; i++) {
        // i번째 가방에 삽입 가능한 보석의 가치들 전부 pq에 삽입
        while(idx < n && jewel[idx].first <= bag[i]) {
            pq.push(jewel[idx++].second);
        }
        if(pq.size()) {
            answer += pq.top();
            pq.pop();
        }
    }
    cout << answer;
    
    return 0;
}
