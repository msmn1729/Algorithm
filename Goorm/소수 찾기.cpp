#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <map>
#include <sstream>
#include <cmath>
#include <cstring>
#include <stack>
#include <unordered_map>
#include <set>
#define ll long long
#define INF 1e9
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    int prime[100001] = {};
    prime[1] = 1;
    
    for(int i=2; i<=n; i++) {
        if(prime[i]) continue;
        for(int j=i+i; j<=n; j+=i) {
            prime[j] = 1;
        }
    }
    
    int ans = 0;
    for(int i=1; i<=n; i++) {
        int num;
        cin >> num;
        if(prime[i] == 0) ans += num;
    }
    
    cout << ans;
    
    return 0;
}
