#include <bits/stdc++.h>
#define ll long long
using namespace std;
// https://www.acmicpc.net/problem/1920 수 찾기

int n;
int ar[100001] = {};

int BiSearch(int a) {
    int st = 0, ed = n - 1;
    int mid = 0;
    
    while(st <= ed) {
        mid = (st + ed) / 2;
        if(a < ar[mid]) ed = mid - 1;
        else if(a > ar[mid]) st = mid + 1;
        else return 1;
    }
    
    return 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    for(int i=0; i<n; i++) cin >> ar[i];
    sort(ar, ar+n);
    
    int m;
    cin >> m;
    for(int i=0; i<m; i++) {
        int a;
        cin >> a;
//        cout << binary_search(ar, ar+n, a) << '\n';
        cout << BiSearch(a) << '\n';
    }
    
    return 0;
}
