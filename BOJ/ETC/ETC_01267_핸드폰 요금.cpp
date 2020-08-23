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

//https://www.acmicpc.net/problem/1267 핸드폰 요금

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, i, M=0, Y=0, in;
    cin >> n;
    for(i=0; i<n; i++)
    {
        cin >> in;
        Y += 10*(in / 30 + 1);
        M += 15*(in / 60 + 1);
    }
    if(M == Y) cout << "Y M " << M;
    else if(M > Y) cout << "Y " << Y;
    else cout << "M " << M;
   
    return 0;
}
