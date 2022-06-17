#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <map>
#include <sstream>
#define ll long long
using namespace std;

int main() {
    int n, b;
    cin >> n >> b;
    
    string ans = "";
    while(n) {
        if(n % b >= 10) ans = (char)((n % b) - 10 + 'A') + ans;
        else ans = to_string(n % b) + ans;
        n /= b;
    }
    
    cout << ans;
    
    return 0;
}
