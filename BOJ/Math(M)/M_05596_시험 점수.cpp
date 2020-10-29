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
#define ll long long

using namespace std;

//https://www.acmicpc.net/problem/5596 시험 점수

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n = 8;
    int sum=0, sum2=0;
    while(n--)
    {
        int in;
        cin >> in;
        if(n>=4) sum += in;
        else sum2 += in;
    }
    cout << (sum > sum2 ? sum : sum2);
    
    return 0;
}

