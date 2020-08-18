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

//https://www.acmicpc.net/problem/11004 K번째 수

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, k, in;
    vector<int> v;
    
    cin >> n >> k;
    
    while(n--)
    {
        cin >> in;
        v.push_back(in);
    }
    sort(v.begin(), v.end());
    cout << v[k-1];
}
