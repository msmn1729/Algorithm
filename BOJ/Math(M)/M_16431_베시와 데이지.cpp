#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int br, bc, dr, dc, jr, jc;
    cin >> br >> bc;
    cin >> dr >> dc;
    cin >> jr >> jc;
    
    int bessie = max(abs(jr - br), abs(jc - bc));
    int daisy = abs(jr - dr) + abs(jc - dc);
    if(bessie < daisy) cout << "bessie";
    else if(bessie > daisy) cout << "daisy";
    else cout << "tie";
    
    return 0;
}
