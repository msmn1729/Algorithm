#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while(1) {
        string s;
        int age, weight;
        cin >> s >> age >> weight;
        if(s == "#" && age == 0 && weight == 0) break;
        if(age > 17 || weight >= 80) cout << s << " " << "Senior";
        else cout << s << " " << "Junior";
        cout << '\n';
    }
    
    return 0;
}

