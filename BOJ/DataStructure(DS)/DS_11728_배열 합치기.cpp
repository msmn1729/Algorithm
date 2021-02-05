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

//https://www.acmicpc.net/problem/11728 배열 합치기

int a[1000001] = {}, b[1000001] = {}, ans[2000002] = {};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     
    int n, m;
    cin >> n >> m;
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<m; i++) cin >> b[i];
    
    int i = 0, j = 0;
    int idx = 0;

    for(i=0, j=0; i<n || j<m; ) {
        if(i == n) ans[idx++] = b[j++];
        else if(j == m) ans[idx++] = a[i++];
        else if(a[i] <= b[j]) ans[idx++] = a[i++]; //stable 성질 유지
        else ans[idx++] = b[j++];
    }
    
    for(int i=0; i<n+m; i++) cout << ans[i] << ' ';
    
    return 0;
}
