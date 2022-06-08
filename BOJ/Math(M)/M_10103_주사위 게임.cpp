#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <map>
#define ll long long
using namespace std;

int main() {
    int n, a, b, score1 = 100, score2 = 100;
    cin >> n;
    
    while(n--) {
        cin >> a >> b;
        if(a < b) {
            score1 -= b;
        } else if(b < a) {
            score2 -= a;
        }
    }
    cout << score1 << '\n' << score2;
    
    return 0;
}
