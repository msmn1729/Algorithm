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
#define ll long long

using namespace std;

//https://www.acmicpc.net/problem/11866 요세푸스 문제 0

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, k;
    cin >> n >> k;
    queue<int> q;
    
    for(int i=1; i<=n; i++) {
        q.push(i);
    }
    
    cout << "<";
    while(q.size()) {
        for(int i=1; i<k; i++) {
            int tmp = q.front();
            q.pop();
            q.push(tmp);
        }
        cout << q.front();
        if(q.size() == 1) cout << ">";
        else cout << ", ";
        q.pop();
    }
    
    return 0;
}
