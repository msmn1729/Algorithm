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
#include <unordered_map>
#include <set>
#define ll long long
using namespace std;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    string name, recode;
    set<string, greater<>> info;
    
    for(int i=0; i<n; i++) {
        cin >> name >> recode;
        if(recode == "enter") info.insert(name);
        else if(recode == "leave") info.erase(name);
    }
    
    for(string s : info) {
        cout << s << '\n';
    }
    
    return 0;
}
