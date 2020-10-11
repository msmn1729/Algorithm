#include <iostream>
using namespace std;

//https://www.acmicpc.net/problem/10409 서버

int main()
{
    int n, t;
    int sum = 0;
    int ans = 0;
    cin >> n >> t;
    for(int i=0; i<n; i++)
    {
        int in;
        cin >> in;
        sum += in;
        if(sum <= t)
        {
            ans++;
        }
    }
    cout << ans;

    return 0;
}
