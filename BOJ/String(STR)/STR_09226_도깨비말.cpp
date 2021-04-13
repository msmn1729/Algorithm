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
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>

#define ll long long
#define INF 1e9

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    while(1) {
        cin >> s;
        if(s == "#") break;
        for(int i=0; i<s.size(); i++) {
            if(s.front() == 'a' || s.front() == 'e' || s.front() == 'i' || s.front() == 'o' || s.front() == 'u') {
                break;
            }
            char tmp = s.front();
            s.push_back(tmp);
            s = s.substr(1, s.size() - 1);
        }
        cout << s << "ay" << '\n';
    }
    
    return 0;
}
