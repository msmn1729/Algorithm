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
#define INF 1e9
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string board[10] = {"", "1.,?!", "2ABC", "3DEF", "4GHI", "5JKL", "6MNO",
        "7PQRS", "8TUV", "9WXYZ"};
    int n;
    cin >> n;
    string s;
    cin >> s;
    
    if(n == 1) cout << s;
    int cnt = 1;
    char prev = s[0];
    for(int i=1; i<n; i++) {
        if(prev == s[i]) {
            cnt++;
            if(i < n-1) continue;
        }
        int num = prev - '0';
        if(num == 1 || num == 7 || num == 9) {
            cnt = (cnt-1)%5 + 1;
        }
        else {
            cnt = (cnt-1)%4 + 1;
        }
        cout << board[num][cnt-1];
        
        num = s[i] - '0';
        if(i == n-1 && prev != s[i]) {
            cout << board[num][0];
        }
        cnt = 1;
        prev = s[i];
    }

    return 0;
}
