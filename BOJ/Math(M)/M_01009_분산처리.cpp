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

//https://www.acmicpc.net/problem/1009 분산처리

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    while(n--)
    {
        int a, b;
        cin >> a >> b;
        int tmp = a % 10;
        if(tmp == 0)
        {
            cout << 10 << '\n';
            continue;
        }
        int result = 1;
        while(b--)
        {
            result *= tmp;
            result %= 10;
        }
        cout << result << '\n';
    }
    return 0;
}
