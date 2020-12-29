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

//https://www.acmicpc.net/problem/5073 삼각형과 세 변

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    while(1) {
        int n;
        vector<int> v;
        
        for(int i=0; i<3; i++) {
            cin >> n;
            v.push_back(n);
        }
        sort(v.begin(), v.end());
        if(!v.back()) break;
        
        int a = v.front(), b = v[1], c = v.back();
        if(a+b <= c) cout << "Invalid";
        else if(a == c) cout << "Equilateral";
        else if(a == b || b == c) cout << "Isosceles";
        else cout << "Scalene";
        cout << '\n';
    }
    
    return 0;
}
