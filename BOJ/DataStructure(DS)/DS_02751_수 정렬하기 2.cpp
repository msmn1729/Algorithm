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
#include <bitset>
#define ll long long
#define INF 1e9

using namespace std;

//https://www.acmicpc.net/problem/2751 수 정렬하기 2

int a[1000001] = {}, tmp[1000001] = {};

//a[st:ed] st 이상 ed 미만
void merge(int st, int ed) {
    int mid = (st+ed)/2;
    int l_idx = st, r_idx = mid;
    
    for(int i=st; i<ed; i++) {
        if(r_idx == ed) tmp[i] = a[l_idx++];
        else if(l_idx == mid) tmp[i] = a[r_idx++];
        else if(a[l_idx] <= a[r_idx]) tmp[i] = a[l_idx++];
        else tmp[i] = a[r_idx++];
    }
    for(int i=st; i<ed; i++) a[i] = tmp[i];
}

void merge_sort(int st, int ed) {
    if(st+1 == ed) return;
    int mid = (st+ed)/2;
    merge_sort(st, mid);
    merge_sort(mid, ed);
    merge(st, ed);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    for(int i=0; i<n; i++) cin >> a[i];
    merge_sort(0, n);
    for(int i=0; i<n; i++) cout << a[i] << '\n';
    
    return 0;
}
