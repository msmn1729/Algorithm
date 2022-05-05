#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    int a, b, c, m;
    int ans = 0;
    
    cin >> a >> b >> c >> m;
    int fatigueLevel = 0;
    for(int i=0; i<24; i++) {
        if(a + fatigueLevel <= m) {
            fatigueLevel += a;
            ans += b;
        } else {
            fatigueLevel -= c;
            fatigueLevel = max(fatigueLevel, 0);
        }
    }
    cout << ans;
}
