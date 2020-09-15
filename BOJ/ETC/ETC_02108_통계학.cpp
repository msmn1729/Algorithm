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
#include <bitset>

using namespace std;

//https://www.acmicpc.net/problem/2108 통계학
//최빈값을 생각해보자!

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, in, maxnum_cnt = -2e9;
    int ar[8001] = {};
    int sum = 0;
    vector<int> v;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> in;
        v.push_back(in);
        ar[in + 4000]++;
        maxnum_cnt = max(maxnum_cnt, ar[in + 4000]);
        sum += in;
    }
    vector<int> mode;
    for(int i=0; i<=8000; i++) //총 8001개
    {
        if(ar[i] == maxnum_cnt)
        {
            mode.push_back(i - 4000);
        }
    }
    sort(mode.begin(), mode.end());
    sort(v.begin(), v.end());
    cout << round((double)sum / n) << '\n';
    cout << v[n/2] << '\n';
    mode.size() >= 2 ? cout << mode[1] << '\n' : cout << mode[0] << '\n';
    cout << v.back() - v.front() << '\n';

    return 0;
}
