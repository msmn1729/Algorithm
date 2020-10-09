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

//https://www.acmicpc.net/problem/1074 Z

int n, r, c;

int func(int n, int r, int c)
{
    if(n == 0) return 0;
    
    int half = 1<<(n-1); //절반
    
    if(r < half && c < half) return func(n-1, r, c);
    else if(r < half && c >= half) return half*half + func(n-1, r, c-half);
    else if(r >= half && c < half) return half*half*2 + func(n-1, r-half, c);
    else return half*half*3 + func(n-1, r-half, c-half);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> r >> c;
    cout << func(n, r, c);
    
    return 0;
}

