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
using namespace std;

bool isPrime(ll n) {
    for(ll i=2; i*i<=n; i++) {
        if(n % i == 0) return false;
    }
    return true;
}

int solution(int n, int k) {
    int answer = 0;
    string s = "";
    
    while(n) {
        s = to_string(n % k) + s;
        n /= k;
    }
    
    stringstream stream(s);
    string buffer;
    
    while(getline(stream, buffer, '0')) {
        if(buffer.empty()) continue;
        ll num = stoll(buffer);
        if(num == 1) continue;;
        answer += isPrime(num);
    }
    
    return answer;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    solution(437674, 3);
    
    return 0;
}
