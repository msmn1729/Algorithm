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

//https://www.acmicpc.net/problem/4504 배수 찾기

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, in;
    vector<int> v;
    cin >> n;
    
    while(cin >> in && in)
    {
        cout << in << " is";
        if(in%n) cout << " NOT";
        cout << " a multiple of " << n << ".\n";
    }
    
    return 0;
}

