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

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout << setprecision(16);
    
    int n, k;
    cin >> n >> k;
    for(int i=1; i<=n; i++)
    {
        l.push_back(i);
        if(i%k == 0)
        {
//            cou << i << ", ";
        }
    }
    while(!l.empty())
    {
        
    }
}
