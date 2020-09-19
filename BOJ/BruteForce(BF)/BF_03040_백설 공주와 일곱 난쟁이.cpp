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

//https://www.acmicpc.net/problem/3040 백성 공주와 일곱 난쟁이

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int in;
    vector<int> v;
    for(int i=0; i<9; i++)
    {
        cin >> in;
        v.push_back(in);
    }
    vector<int> vc(9);
    for(int i=2; i<9; i++)
    {
        vc[i] = 1;
    }
    do
    {
        int sum = 0;
        for(int i=0; i<9; i++)
        {
            if(vc[i])
            {
                sum += v[i];
//                cout << v[i] << ' ';
            }
        }
        if(sum == 100)
        {
            for(int i=0; i<9; i++)
            {
                if(vc[i]) cout << v[i] << '\n';
            }
            break;
        }
    } while(next_permutation(vc.begin(), vc.end()));

    return 0;
}
