#include <bits/stdc++.h>
#define ll long long
using namespace std;
// https://www.acmicpc.net/problem/10768 특별한 날

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int a, b;
    cin >> a >> b;
    int sum = (a - 1) * 31 + b;
    if(31 + 18 < sum) cout << "After";
    else if(31 + 18 > sum) cout << "Before";
    else cout << "Special";
    
    return 0;
}
