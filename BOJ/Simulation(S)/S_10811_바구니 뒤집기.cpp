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

//https://www.acmicpc.net/problem/10811 바구니 뒤집기

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, i;
    int ar[101] = {};
    cin >> n >> m;
    for(i=1; i<=n; i++)
    {
        ar[i] = i;
    }
    int st, ed;
    for(i=0; i<m; i++)
    {
        cin >> st >> ed;
        for(int j=0; j<(ed-st+1)/2; j++)
        {
            int tmp = ar[st+j];
            ar[st+j] = ar[ed-j];
            ar[ed-j] = tmp;
        }
    }
    for(i=1; i<=n; i++)
    {
        cout << ar[i] << ' ';
    }
    return 0;
}

