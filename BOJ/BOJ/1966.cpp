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

list<int> l;
vector<int> v;
queue<int> q;

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout << setprecision(16);

    int t, n, m, in;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        while(n--)
        {
            cin >> in;
            q.push(in);
        }
    }
}
