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
    
    string document, searchWord;
    getline(cin, document);
    getline(cin, searchWord);
    
    int idx = (int)document.find(searchWord);
    int ans = 0;
    
    while(idx >= 0) {
        document.replace(idx, searchWord.size(), "1");
        idx = (int)document.find(searchWord);
        ans++;
    }
    cout << ans;
    
    return 0;
}
