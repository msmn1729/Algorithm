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

//https://www.acmicpc.net/problem/12755 수면 장애

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    
    for(int i=1; i<=1e8; i++) {
        string num_str = to_string(i);
        int num_len = (int)num_str.size();
        n -= num_len;
        if(n <= 0) {
            int idx = n + num_len - 1;
            cout << num_str[idx];
            break;
        }
    }
    
    return 0;
}
