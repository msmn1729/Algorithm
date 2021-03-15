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

//https://www.acmicpc.net/problem/15650 N과 M (2)

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, m;
    int combi[10] = {};
    cin >> n >> m;
    vector<int> v(n, 1);
    for(int i=0; i<n; i++) combi[i] = i+1;
    for(int i=0; i<m; i++) v[i] = 0;
    
    do {
        for(int i=0; i<n; i++) {
            if(v[i] == 0) {
                cout << combi[i] << ' ';
            }
        }
        cout << '\n';
    } while(next_permutation(v.begin(), v.end()));
    
    return 0;
}
