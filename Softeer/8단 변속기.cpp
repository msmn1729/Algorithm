#include <iostream>
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int cnt = 0, cnt2 = 0;
    for(int i=1; i<=8; i++) {
        int n;
        cin >> n;
        if(i == n) cnt++;
        else if(8-i+1 == n) cnt2++;
    }
    if(cnt == 8) cout << "ascending";
    else if(cnt2 == 8) cout << "descending";
    else cout << "mixed";
    
    return 0;
}
