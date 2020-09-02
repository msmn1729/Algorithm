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
    
    int n, k, cnt=1, start=1;
    cin >> n >> k;
    for(int i=1; i<=n; i++)
    {
        l.push_back(i);
    }
    
    auto i = l.begin();
    for(; !l.empty(); cnt++)
    {
        if(i == l.end()) i = l.begin();
        if(cnt%k == 0) //k번 째 마다
        {
            if(start)
            {
                cout << '<' << *i;
                start = 0;
            }
            else cout << ", " << *i;
            i = l.erase(i); //출력한 원소 삭제
        }
        else i++;
    }
    cout << '>';
}
