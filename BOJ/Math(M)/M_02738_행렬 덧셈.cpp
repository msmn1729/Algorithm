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
    
    int ar[101][101] = {};
    int n, m;
    cin >> n >> m;
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> ar[i][j];
        }
    }
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            int num;
            cin >> num;
            cout << ar[i][j] + num << ' ';
        }
        cout << '\n';
    }
    
    return 0;
}
