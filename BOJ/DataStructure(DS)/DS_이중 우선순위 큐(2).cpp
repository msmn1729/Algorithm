#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <map>
#include <sstream>
#include <cmath>
#include <cstring>
#include <stack>
#include <set>
#include <unordered_map>
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin >> t;
    int n;
    
    while(t--) {
        cin >> n;
        multiset<int> ms;
        
        for(int i=0; i<n; i++) {
            string s;
            int num;
            cin >> s >> num;
            
            if(s == "I") {
                ms.insert(num);
            }
            else if(s == "D" && num == 1) {
                if(ms.empty()) continue;
                ms.erase(--ms.end());
            }
            else if(s == "D" && num == -1) {
                if(ms.empty()) continue;
                ms.erase(ms.begin());
            }
        }
        
        if(ms.empty()) cout << "EMPTY\n";
        else cout << *(--ms.end()) << ' ' << *ms.begin() << '\n';
    }
    
    return 0;
}
