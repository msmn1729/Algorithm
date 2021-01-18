#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <string>
#include <map>
#include <iomanip>
#include <list>
#include <stack>
#include <cstring>
#include <cmath>
#include <set>
#include <unordered_map>
#include <bitset>
#define ll long long

using namespace std;

//https://www.acmicpc.net/problem/7662 이중 우선순위 큐

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t, n;
    cin >> t;
    
    while(t--) {
        multiset<int> ms;
        cin >> n;
        while(n--) {
            char c;
            int in;
            cin >> c >> in;
            if(c == 'I') {
                ms.insert(in);
            }
            else if(c == 'D' && ms.size()) {
                if(in == 1) {
                    ms.erase(--ms.end());
                }
                else if(in == -1) {
                    ms.erase(ms.begin());
                }
            }
        }
        if(ms.size()) cout << *--ms.end() << ' ' << *ms.begin();
        else cout << "EMPTY";
        cout << '\n';
    }
    return 0;
}
