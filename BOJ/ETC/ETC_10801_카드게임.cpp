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
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int ar[10] = {};
    int aCnt = 0, bCnt = 0;
    
    for(int i=0; i<10; i++) cin >> ar[i];
    for(int i=0; i<10; i++) {
        int in;
        cin >> in;
        if(ar[i] > in) {
            aCnt++;
        }
        else if(ar[i] < in) {
            bCnt++;
        }
    }
    
    if(aCnt > bCnt) cout << "A";
    else if(aCnt < bCnt) cout << "B";
    else cout << "D";
    
    return 0;
}
