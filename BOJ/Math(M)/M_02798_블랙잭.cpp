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

//https://www.acmicpc.net/problem/2798 블랙잭

int ans;
int n, m;
int ar[101] = {};
int mn = 2e9;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for(int i=0; i<n; i++) cin >> ar[i];
    
    vector<int> v(n, 1);
    for(int i=0; i<3; i++) v[i] = 0;
    
    do {
        int sum = 0;
        for(int i=0; i<n; i++) {
            if(!v[i]) {
                sum += ar[i];
            }
        }
        if(0 <= m-sum && m-sum < mn) {
            mn = m-sum;
            ans = sum;
        }
    } while(next_permutation(v.begin(), v.end()));
    cout << ans;
    
    return 0;
}
