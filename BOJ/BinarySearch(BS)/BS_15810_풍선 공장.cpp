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

//https://www.acmicpc.net/problem/15810 풍선 공장

int main(void)
{
    int n, balloon;
    cin >> n >> balloon;
    vector<int> v(n);
    for(int i=0; i<n; i++) cin >> v[i];
    
    ll low = 1, high = 1e12, mid = 0, sum = 0;
    while(low < high-1)
    {
        mid = (low+high)/2;
        sum = 0;
        for(int i=0; i<n; i++)
        {
            sum += mid/v[i];
        }
        sum >= balloon ? (high = mid) : (low = mid);
    }
    cout << high;
    
    return 0;
}
