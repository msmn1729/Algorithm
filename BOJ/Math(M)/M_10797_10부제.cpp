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

//https://www.acmicpc.net/problem/10797 10부제

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, ans=0;
    cin >> n;
    for(int i=0; i<5; i++)
    {
        int in; cin >> in;
        if(in%10 == n) ans++;
    }
    cout << ans;
    
    return 0;
}
