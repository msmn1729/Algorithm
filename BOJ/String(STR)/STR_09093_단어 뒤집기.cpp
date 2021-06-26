#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iostream>
#include <climits>
#include <cstring>
#include <iomanip>
#include <bitset>
#include <string>
#include <vector>
#include <cmath>
#include <deque>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    cin.ignore();
    
    while(n--) {
        string s;
        getline(cin, s);
        string tmp;
        
        for(int i=0; i<s.size(); i++) {
            char c = s[i];
            if(c != ' ') tmp += c;
            if(c == ' ' || i == s.size()-1) {
                reverse(tmp.begin(), tmp.end());
                cout << tmp << ' ';
                tmp = "";
            }
        }
        cout << '\n';
    }
    
    return 0;
}
