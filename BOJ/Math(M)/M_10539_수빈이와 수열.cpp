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

using namespace std;

//https://www.acmicpc.net/problem/10539 수빈이와 수열

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, i, sum = 0, in;
    cin >> n;
    for(i=1; i<=n; i++)
    {
        cin >> in;
        cout << in * i - sum << ' ';
        sum = in * i;
    }
    return 0;
}

