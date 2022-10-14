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
    
    int ans = 0;
    for(int i=0; i<document.size(); i++) {
        int flag = 0;
        
        for(int j=0; j<searchWord.size(); j++) {
            if(document[i+j] == searchWord[j]) continue;
            flag = 1;
            break;
        }
        if(!flag) {
            ans++;
            i += searchWord.size() - 1;
        }
    }
    cout << ans;
    
    return 0;
}
