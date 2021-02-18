#include <unordered_map>
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

//https://www.acmicpc.net/problem/1247 부호

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    for(int i=0; i<3; i++) {
        int n;
        cin >> n;
        int overflow = 0;
        ll in;
        ll sum = 0;
        while(n--) {
            cin >> in;
            if(in > 0 && LLONG_MAX - in < sum) overflow++;
            else if(in < 0 && LLONG_MIN - in > sum) overflow--;
            sum += in;
        }
        if(overflow > 0) cout << "+";
        else if(overflow < 0) cout << "-";
        else {
            if(sum > 0) cout << "+";
            else if(sum < 0) cout << "-";
            else cout << "0";
        }
        cout << '\n';
    }
    
    return 0;
}
