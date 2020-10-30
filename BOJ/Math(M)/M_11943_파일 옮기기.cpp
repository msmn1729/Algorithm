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
#define ll long long

using namespace std;

//https://www.acmicpc.net/problem/11943 파일 옮기기

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int ans;
    ans = min(a+d, b+c);
    cout << ans;
    
    return 0;
}

