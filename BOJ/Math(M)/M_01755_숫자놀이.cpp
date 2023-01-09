#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    
    string ar[10] = {"zero", "one", "two", "three", "four", "five",
        "six", "seven", "eight", "nine"};
    vector<pair<string, int> > v;
    
    for(int i=n; i<=m; i++) {
        string s = "";
        if(i >= 10) s = ar[i/10] + " " + ar[i%10];
        else s = ar[i] + "";
        v.push_back({s, i});
    }
    
    sort(v.begin(), v.end());
    
    for(int i=0; i<v.size(); i++) {
        cout << v[i].second << ' ';
        if((i + 1) % 10 == 0) cout << '\n';
    }
    
    return 0;
}
