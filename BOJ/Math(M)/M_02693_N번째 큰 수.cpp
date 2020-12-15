#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <string>
#include <map>
#include <iomanip>
#include <list>
#include <stack>
#include <cstring>
#include <cmath>
#include <set>
#include <unordered_map>
#define ll long long

using namespace std;

//https://www.acmicpc.net/problem/2693 N번째 큰 수

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    
    while(n--) {
        vector<int> v;
        for(int i=0; i<10; i++) {
            int in;
            cin >> in;
            v.push_back(in);
        }
        sort(v.begin(), v.end());
        cout << v[7] << '\n';
    }
    
    return 0;
}
