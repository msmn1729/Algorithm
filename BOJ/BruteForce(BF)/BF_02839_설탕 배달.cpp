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

//https://www.acmicpc.net/problem/2839 설탕 배달
//14:50

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for(int i=n/5; i>=0; i--) {
        for(int j=0; j<=n/3; j++) {
            if(5*i + 3*j == n) {
                cout << i+j;
                return 0;
            }
        }
    }
    cout << -1;
    
    return 0;
}
