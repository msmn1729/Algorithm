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

//https://www.acmicpc.net/problem/10804 카드 역배치

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int i, x[21]={};
    for(i=0; i<20; i++) x[i] = i+1;
    for(i=0; i<10; i++)
    {
        int s, e;
        cin >> s >> e;
        reverse(x+s-1, x+e);
    }
    for(i=0; i<20; i++) cout << x[i] << ' ';
    return 0;
}
