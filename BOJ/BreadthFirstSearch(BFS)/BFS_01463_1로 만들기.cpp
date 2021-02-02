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
#define INF 1e9

using namespace std;

//https://www.acmicpc.net/problem/1463 1로 만들기

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    int dist[(int)1e6 + 1] = {};
    
    queue<int> q;
    q.push({n});
    dist[n] = 1;
    
    while(q.size()) {
        int x = q.front();
        q.pop();
        if(x == 1) {
            cout << dist[x]-1;
            return 0;
        }
        if(x%3 == 0 && !dist[x/3]) {
            q.push({x/3});
            dist[x/3] = dist[x] + 1;
        }
        if(x%2 == 0 && !dist[x/2]) {
            q.push({x/2});
            dist[x/2] = dist[x] + 1;
        }
        if(x && !dist[x-1]) {
            q.push({x-1});
            dist[x-1] = dist[x] + 1;
        }
    }
    
    return 0;
}
