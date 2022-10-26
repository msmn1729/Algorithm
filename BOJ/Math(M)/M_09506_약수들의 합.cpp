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

    int n;
    while(1) {
        cin >> n;
        if(n == -1) break;
        vector<int> v;
        int sum = 0;
        for(int i=1; i<=n/2; i++) {
            if(n%i == 0) {
                v.push_back(i);
                sum += i;
            }
        }
        if(sum == n) {
            cout << n << " = " << v[0];
            for(int i=1; i<v.size(); i++) {
                cout << " + " << v[i];
            }
        }
        else {
            cout << n << " is NOT perfect.";
        }
        cout << '\n';
    }

    return 0;
}
