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
#include <bitset>
#define ll long long

using namespace std;

//https://www.acmicpc.net/problem/3040 백설 공주와 일곱 난쟁이

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int in, sum = 0;
    vector<int> v;
    for(int i=0; i<9; i++)
    {
        cin >> in;
        v.push_back(in);
        sum += in;
    }
    for(int i=0; i<9; i++)
    {
        for(int j=i+1; j<9; j++)
        {
            if(sum - v[i] - v[j] == 100)
            {
                for(int it : v)
                {
                    if(it == v[i] || it == v[j]) continue;
                    cout << it << '\n';
                }
            }
        }
    }
    return 0;
}
