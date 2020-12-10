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

//https://www.acmicpc.net/problem/1668 트로피 진열

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, left = 1, right = 1, mx = 0;
    vector<int> v;
    cin >> n;
    while(n--) {
        int in;
        cin >> in;
        v.push_back(in);
    }
    mx = v.front();
    for(int i=1; i<v.size(); i++) {
        if(mx < v[i]) {
            mx = v[i];
            left++;
        }
    }
    mx = v.back();
    for(int i=(int)v.size()-1; i>=0; i--) {
        if(mx < v[i]) {
            mx = v[i];
            right++;
        }
    }
    cout << left << '\n' << right;
    
    return 0;
}
