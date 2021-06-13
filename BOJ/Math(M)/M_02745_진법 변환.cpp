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
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);
    
    string s;
    ll n, sum = 0;
    cin >> s >> n;
    reverse(s.begin(), s.end());
    
    for(int i=0; i<s.size(); i++) {
        if(isalpha(s[i])) sum += (s[i] - 'A' + 10) * pow(n, i);
        else sum += (s[i] - '0') * pow(n, i);
    }
    
    cout << sum;
    
    return 0;
}

 
