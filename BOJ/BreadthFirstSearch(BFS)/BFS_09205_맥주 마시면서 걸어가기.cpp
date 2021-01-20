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

//https://www.acmicpc.net/problem/9205 맥주 마시면서 걸어가기


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        int n;
        int x[103] = {};
        int y[103] = {};
        int adj[103][103] = {};
        
        cin >> n;
        n += 2;
        for(int i=0; i<n; i++) cin >> x[i] >> y[i];
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(i == j) continue;
                int dist = abs(x[i] - x[j]) + abs(y[i] - y[j]);
                if(dist <= 1000) adj[i][j] = 1;
            }
        }
    
        for(int k=0; k<n; k++) {
            for(int i=0; i<n; i++) {
                for(int j=0; j<n; j++) {
                    if(adj[i][k] && adj[k][j]) adj[i][j] = 1;
                }
            }
        }
        if(adj[0][n-1]) cout << "happy";
        else cout << "sad";
        cout << '\n';
    }
    return 0;
}
