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

//https://www.acmicpc.net/problem/14582 오늘도 졌다

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int i, tmp;
    int sum1 = 0, sum2 = 0;
    int ar[10] = {};
    for(i=0; i<9; i++) cin >> ar[i];
    
    sum1 = ar[0];
    bool flag = false;
    for(i=0; i<9; i++)
    {
        cin >> tmp;
        if(sum1 > sum2)
        {
            flag = true;
        }
        sum2 += tmp;
        if(i<9) sum1 += ar[i+1];
    }
    
    if(flag && (sum1 < sum2)) cout << "Yes";
    else cout << "No";
    
    return 0;
}
