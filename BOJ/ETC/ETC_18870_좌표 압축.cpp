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

//https://www.acmicpc.net/problem/18870 좌표 압축

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
   
    int n;
    cin >> n;
    vector<int> v(n), v2(n);
    for(int i=0; i<n; i++) {
        cin >> v[i];
        v2[i] = v[i];
    }
    
    sort(v.begin(), v.end());
    map<int, int> m;
    int cnt = 1;
    for(int i=1; i<n; i++) {
        if(v[i-1] != v[i]) {
            m[v[i]] = cnt++;
        }
    }
    
    for(int i=0; i<n; i++) {
        cout << m[v2[i]] << ' ';
    }
    
    
    return 0;
}
