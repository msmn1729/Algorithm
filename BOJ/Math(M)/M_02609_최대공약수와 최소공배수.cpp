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
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>

#define ll long long
#define INF 1e9

using namespace std;

//https://www.acmicpc.net/problem/2609 최대공약수와 최소공배수

int GCD(int a, int b) {
    if(b == 0) return a;
    return GCD(b, a%b);
}

int LCM(int a, int b) {
    return a*b/GCD(a, b);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int a, b;
    cin >> a >> b;
    
    cout << GCD(a, b) << '\n';
    cout << LCM(a, b);
    
    return 0;
}
