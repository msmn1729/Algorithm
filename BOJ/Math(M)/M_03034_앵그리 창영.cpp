#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, w, h;
    cin >> n >> w >> h;
    double diagonal = sqrt(w*w + h*h);
    
    while(n--) {
        int in;
        cin >> in;
        if(in <= diagonal) cout << "DA";
        else cout << "NE";
        cout << '\n';
    }
    
    return 0;
}
