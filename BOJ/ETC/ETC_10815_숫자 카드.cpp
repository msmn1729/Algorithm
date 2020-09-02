#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <string>
#include <map>
#include <iomanip>

using namespace std;
//vector<int>
vector<int> v;

int BSearch(int findData)
{
    int start=0, end = (int)v.size()-1, mid=0;
    while(start<=end)
    {
        mid = (start+end)/2;
        if(findData < v[mid]) end = mid-1;
        else if(findData > v[mid]) start = mid+1;
        else return 1;
    }
    return 0;
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout << setprecision(16);
    
    int n, i, in;
    cin >> n;
    for(i=0; i<n; i++)
    {
        cin >> in;
        v.push_back(in);
    }
    sort(v.begin(), v.end());
    cin >> n;
    for(i=0; i<n; i++)
    {
        cin >> in;
        if(binary_search(v.begin(), v.end(), in)) cout << 1;
        else cout << 0;
        cout << ' ';
    }
}
