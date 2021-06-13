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
    int n;
    cin >> s >> n;
    cout << stoi(s, 0, n);

    return 0;
}
