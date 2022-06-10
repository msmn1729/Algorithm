#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <map>
#define ll long long
using namespace std;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    
    c += d;
    b += c/60;
    a += b/60;
    
    c %= 60;
    b %= 60;
    a %= 24;
    
    cout << a << ' ' << b << ' ' << c;
    
    return 0;
}
