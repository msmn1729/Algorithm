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

//https://www.acmicpc.net/problem/1350 진짜 공간

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n, cluster;
    vector<ll> v;
    cin >> n;
    
    while(n--) {
        int in;
        cin >> in;
        if(in) v.push_back(in);
    }

    cin >> cluster;
    ll mul = 0;
    for(auto it : v) {
        mul += (it/cluster)+1;
        if(it%cluster == 0) mul--;
    }
    cout << cluster*mul;
    
    return 0;
}

