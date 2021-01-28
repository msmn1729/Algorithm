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

//https://www.acmicpc.net/problem/20361 일우는 야바위꾼

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, x, k;
    cin >> n >> x >> k;
    
    while(k--) {
        int a, b;
        cin >> a >> b;
        if(a == x) x = b;
        else if(b == x) x = a;
    }
    cout << x;
    
    return 0;
}
