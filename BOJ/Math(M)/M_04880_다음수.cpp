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

//https://www.acmicpc.net/problem/4880 다음수

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while(1)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if(!a && !b && !c) break;
        if(a+c == 2*b) cout << "AP " << 2*c-b << '\n';
        else cout << "GP " << c*c/b << '\n';
    }
    return 0;
    
    return 0;
}

