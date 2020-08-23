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

using namespace std;

//https://www.acmicpc.net/problem/14581 팬들에게 둘러싸인 홍준

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    string s;
    cin >> s;
    cout << ":fan::fan::fan:\n";
    cout << ":fan::" << s << "::fan:\n";
    cout << ":fan::fan::fan:\n";
    
    return 0;
}
