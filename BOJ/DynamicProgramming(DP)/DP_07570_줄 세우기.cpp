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

//https://www.acmicpc.net/problem/7570 줄 세우기

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, cnt = 0;
    int ar[1000001] = {};
    cin >> n;
    for(int i=0; i<n; i++)
    {
        int in;
        cin >> in;
        ar[in] = ar[in-1]+1;
        cnt = max(cnt, ar[in]);
    }
    cout << n - cnt;
    
    return 0;
}
