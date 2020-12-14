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

//https://www.acmicpc.net/problem/2875 대회 or 인턴

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, m, k;
    cin >> n >> m >> k;
    
    for(; k>0; k--) {
        if(n < m*2) m--; //남자가 남는 경우
        else n--; //여자가 남는 경우
    }
    if(n < m*2) m = n/2; //이게 없으면 반례)5 3 0일 때, 3이 나옴
    
    cout << m;
    
    return 0;
}
