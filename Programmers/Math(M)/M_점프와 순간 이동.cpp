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
#define ll long long
using namespace std;

int solution(int n) {
    int ans = 0;
    
    while(n) {
        if(n % 2) ans++;
        n /= 2;
    }
    
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    solution(5);
    
    return 0;
}
