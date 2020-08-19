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
#include <cstdlib>
#include <cmath>

using namespace std;

//https://www.acmicpc.net/problem/2485 가로수 실버4
//최대공약수 구현

int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a%b);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, i, in, total_len=0, max_interval=1e9, idx=0;
    vector<int> v, dif;

    cin >> n;
    while(n--)
    {
        cin >> in;
        v.push_back(in);
    }
    sort(v.begin(), v.end());
    for(i=0; i<v.size()-1; i++)
    {
        dif.push_back(abs(v[i] - v[i+1]));
        if(i >= 1)
        {
            max_interval = min(max_interval, gcd(dif[idx], dif[idx+1]));
            idx++;
        }
    }
    total_len = v[v.size()-1] - v[0];
    cout << total_len / max_interval - v.size() + 1;

    return 0;
}
