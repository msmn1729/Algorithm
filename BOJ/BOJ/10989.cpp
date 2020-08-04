#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <string>
#include <map>
#include <iomanip>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout << setprecision(16);
    
    int a[10001]={};
    int n, i, j, in;
    cin >> n;
    for(i=0; i<n; i++)
    {
        cin >> in;
        a[in]++;
    }
    
    for(i=1; i<=10000; i++)
    {
        for(j=0; j<a[i]; j++)
        {
            cout << i << '\n';
        }
    }
}
