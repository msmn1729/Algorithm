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

//https://www.acmicpc.net/problem/2997 네 번째 수

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<int> v;
    for(int i=0; i<3; i++) {
        int n;
        cin >> n;
        v.push_back(n);
    }
    sort(v.begin(), v.end());
    
    int ans = 0;
    if(v.front()+v.back() == v[1]*2) { //연속된 경우
        ans = v.back() + (v[1] - v.front());
    }
    else { //연속되지 않은 경우
        ans = v.front() + v.back() - v[1];
    }
    cout << ans;
    
    return 0;
}

