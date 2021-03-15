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

//https://www.acmicpc.net/problem/2751 수 정렬하기 2

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    int ar[2000001] = {};
    cin >> n;
    for(int i=0; i<n; i++) {
        int a;
        cin >> a;
        a += 1e6;
        ar[a]++;
    }
    
    for(int i=0; i<=2e6; i++) {
        if(ar[i] > 0) cout << i - 1000000 << '\n';
    }
    
    return 0;
}
