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

//https://www.acmicpc.net/problem/5576 콘테스트

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<int> v;
    for(int i=0; i<20; i++) {
        int n;
        cin >> n;
        v.push_back(n);
    }
    sort(v.begin(), v.begin()+10);
    sort(v.begin()+10, v.end());
    
    int sum = 0;
    for(int i=7; i<10; i++) {
        sum += v[i];
    }
    cout << sum << ' ';
    sum = 0;
    for(int i=17; i<20; i++) {
        sum += v[i];
    }
    cout << sum;
    
    return 0;
}

