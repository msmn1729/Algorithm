#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <string>
#include <map>
#include <iomanip>

using namespace std;
vector<pair<int, string>> v;

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout << setprecision(16);

    string s, tmp;
    int n, i;

    cin >> n;
    for(i=0; i<n; i++)
    {
        cin >> s; //공백에서 토큰됨
        v.push_back(make_pair(s.length(), s));
    }

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for(auto it=v.begin(); it!=v.end(); it++) cout << it->second << '\n';
}
