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

//https://www.acmicpc.net/problem/15873 공백 없는 A+B

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    int ans = 0;
    cin >> n;
    if(n%10 == 0) ans = n/100 + 10;
    else ans = n%10 + n/10;
    cout << ans;
    
    return 0;
}

