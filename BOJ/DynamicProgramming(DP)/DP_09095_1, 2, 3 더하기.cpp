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
#include <sstream>
#include <stdlib.h>

#define MAX_SIZE 1000000
int num[100];
int combi[MAX_SIZE];
int n, s, sum, ans, cnt;

using namespace std;
vector<string> V;

void DFS(int start, int depth)
{
    if(depth > 0) //합과 같으면서 깊이가 1이상인 경우
    {
        for(int i=0; i<depth; i++)
        {
            //cout << combi[i] << ' ';
            sum += combi[i];
        }
        if(sum == n)
        {
            //ans++;
            char str[100] = {};
            for(int i=0; i<depth; i++)
            {
//                cout << combi[i] << ' ';
                str[i] = combi[i] + '0';
                //sum += combi[i];
            }
            V.push_back(str);
//            strcpy(str, 0);
            cnt++;
//            cout << V.back();
//            cout << '\n';
        }
        sum = 0;

    }
    for(int i=start; i<n; i++)
    {
        for(int j=1; j<=3; j++)
        {
            combi[depth] = j;
            DFS(i+1, depth+1);
        }

        //sum += num[i];
    }
}

int DP(int n)
{
    if(n == 1) return 1;
    else if(n == 2) return 2;
    else if(n == 3) return 4;
    return DP(n-1) + DP(n-2) + DP(n-3);
}

int main()
{
//    //18:07~ 30분 잡고 대결
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);
//    cout << setprecision(16);
//
////    for(int i=0; i<100; i++)
////    {
////        num[i] = i%3+1;
////        //cout << num[i] << '\n';
////    }
//    int k;
//    cin >> k;
//    for(int i=0; i<k; i++)
//    {
//        ans = 0;
//        cin >> n;
//        DFS(0, 0);
//        sort(V.begin(), V.end());
//        V.erase(unique(V.begin(), V.end()), V.end());
//        while(!V.empty())
//        {
//            cout << V.back() << '\n';
//            V.pop_back();
//            ans++;
//        }
//        cout << ans << '\n';
//    }
    
    
    //분할정복, DP로 해결
    int k, n;
    cin >> k;
    while(k--)
    {
        cin >> n;
        cout << DP(n) << '\n';
    }
}
