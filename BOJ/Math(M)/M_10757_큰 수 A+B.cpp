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

using namespace std;

//https://www.acmicpc.net/problem/10757 큰 수 A+B

string stringAdd(string a, string b)
{
    int sum = 0;
    string result;
    while(a.size() || b.size() || sum)
    {
        if(a.size())
        {
            sum += a.back() - '0';
            a.pop_back();
        }
        if(b.size())
        {
            sum += b.back() - '0';
            b.pop_back();
        }
        result.push_back(sum%10 + '0');
        sum /= 10;
    }
    reverse(result.begin(), result.end());
    return result;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    string a, b;
    cin >> a >> b;
    cout << stringAdd(a, b);

    return 0;
}
