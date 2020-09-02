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
using namespace std;

//https://www.acmicpc.net/problem/1629
//O(b)는 21억이라 시간초과뜸
//O(log b)로 풀면 해결됨

using ll = long long;

ll func(ll a, ll b, ll m) //O(b)
{
    ll val = 1;
    while(b--) val = val * a % m;
    return val;
}
ll POW(ll a, ll b, ll m) //O(log b) b가 절반씩 줄어듦
{
    //base condition
    if(b == 0) return 1; //바로 해결
    ll val = POW(a, b/2, m); //지수를 절반
    val = val * val % m;
    if(b%2 == 0) return val;
    return a * val % m;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll a,b,c;
    cin >> a >> b >> c;
    cout << POW(a, b, c);
}
