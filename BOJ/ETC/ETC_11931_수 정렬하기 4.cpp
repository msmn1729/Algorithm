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

//https://www.acmicpc.net/problem/11931 수 정렬하기 4

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    vector<int> v(2e6 + 2);
    for(int i=0; i<n; i++)
    {
        int in;
        cin >> in;
        v[in + 1e6]++;
    }
    for(int i=2e6; i>=0; i--) if(v[i]) cout << i - 1000000 << '\n';
    
    return 0;
}
