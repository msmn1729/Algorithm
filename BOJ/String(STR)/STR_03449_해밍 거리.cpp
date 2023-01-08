#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    
    while(n--) {
        string s1, s2;
        cin >> s1 >> s2;
        int hammingDistance = 0;
        
        for(int i=0; i<s1.size(); i++) {
            if(s1[i] == s2[i]) continue;
            hammingDistance++;
        }
        cout << "Hamming distance is " << hammingDistance << ".\n";
    }
    
    return 0;
}
