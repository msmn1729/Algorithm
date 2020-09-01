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

//https://www.acmicpc.net/problem/18258 큐 2

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, in;
    string s;
    queue<int> q;
    cin >> n;
    while(n--)
    {
        cin >> s;
        if(s == "push")
        {
            cin >> in;
            q.push(in);
        }
        else if(s == "pop")
        {
            if(q.empty()) cout << -1 << '\n';
            else
            {
                cout << q.front() << '\n';
                q.pop();
            }
        }
        else if(s == "size")
        {
            cout << q.size() << '\n';
        }
        else if(s == "empty")
        {
            if(q.empty()) cout << 1 << '\n';
            else cout << 0 << '\n';
        }
        else if(s == "front")
        {
            if(q.empty()) cout << -1 << '\n';
            else cout << q.front() << '\n';
        }
        else if(s == "back")
        {
            if(q.empty()) cout << -1 << '\n';
            else cout << q.back() << '\n';
        }
    }

    return 0;
}

