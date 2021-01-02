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

//https://www.acmicpc.net/problem/13015 별 찍기 - 23

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, i, j;
    cin >> n;
    
    for(i=0; i<n; i++) cout << '*';
    for(i=0; i<2*n-3; i++) cout << ' ';
    for(i=0; i<n; i++) cout << '*';
    cout << '\n';
    
    for(i=0; i<n-1; i++) {
        for(j=0; j<=i; j++) cout << ' ';
        cout << '*';
        for(j=0; j<n-2; j++) cout << ' ';
        cout << '*';
        for(j=0; j<(n-2)*2-i*2-1; j++) cout << ' ';
        if(i<n-2) cout << '*';
        for(j=0; j<n-2; j++) cout << ' ';
        cout << '*';
        cout << '\n';
    }
    
    for(i=0; i<n-2; i++) {
        for(j=0; j<n-i-2; j++) cout << ' ';
        cout << '*';
        for(j=0; j<n-2; j++) cout << ' ';
        cout << '*';
        for(j=0; j<i*2+1; j++) cout << ' ';
        if(i<n-2) cout << '*';
        for(j=0; j<n-2; j++) cout << ' ';
        cout << '*';
        cout << '\n';
    }
    for(i=0; i<n; i++) cout << '*';
    for(i=0; i<2*n-3; i++) cout << ' ';
    for(i=0; i<n; i++) cout << '*';
    cout << '\n';
    
    return 0;
}
