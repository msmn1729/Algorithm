#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iostream>
#include <climits>
#include <cstring>
#include <iomanip>
#include <bitset>
#include <string>
#include <vector>
#include <cmath>
#include <deque>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>

#define ll long long
#define INF 1e9

using namespace std;

//https://www.acmicpc.net/problem/2108 통계학

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    vector<int> v;
    int sum = 0;
    int many_num = 0;
    map<int, int> m;
    
    cin >> n;
    for(int i=0; i<n; i++) {
        int a;
        cin >> a;
        v.push_back(a);
        sum += a;
        m[a]++;
    }
    
    //최빈값을 찾기 위해 맵의 밸류로 정렬
    vector<pair<int, int> > vm(m.begin(), m.end());
    sort(vm.begin(), vm.end(), [](pair<int, int> a, pair<int, int> b) {
        return a.second > b.second;
    });
    
    many_num = vm[0].first;
    if(vm[0].second == vm[1].second) many_num = vm[1].first;
    
    sort(v.begin(), v.end());
    
    cout << round((double)sum / n) << '\n';
    cout << v[v.size()/2] << '\n';
    cout << many_num << '\n';
    cout << v.back() - v.front();
    
    return 0;
}
