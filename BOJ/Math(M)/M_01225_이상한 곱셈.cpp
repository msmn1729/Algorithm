#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    string a, b;
    cin >> a >> b;
    long long ans = 0;
    
    for(char c: a) {
        for(char c2: b) {
            ans += (c - '0') * (c2 - '0');
        }
    }
    cout << ans;
    
    return 0;
}
