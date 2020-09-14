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

void dfs(int n, int depth)
{
    if(n < 10)
    {
        cout << depth << ", " << n << '\n';
        return;
    }
}

vector<int> solution(int n)
{
    vector<int> ans;
    
    int mn = 2e9;
    int cnt = 0;
    if(n < 10)
    {
        ans.push_back(cnt);
        ans.push_back(n);
    }
    else
    {
        //        string tmp = "";
        //        int j=0;
        //        for(j=(int)s.size()-1; j>=0; j--)
        //        {
        //            if(s[j] == '0') break;
        ////            tmp += s[j];
        //        }
        //        if(tmp != "")
        //        {
        //            tmp = s.substr(0, j+1);
        //            int st = stoi(tmp);
        //            cout << st;
        //        }

        int st = 0;
        while(mn > 10)
        {
            
            string s = to_string(n);
            cnt++;
            for(int i=10; ; i*=10)
            {
                string tmp = "";
                int j=0;
                for(j=(int)s.size()-1; j>=0; j--)
                {
                    if(s[j] == '0') break;
//                    tmp += s[j];
                }
                if(j >= 0)
                {
                    tmp = s.substr(0, j+1);
                    st = stoi(tmp);
//                    cout << st << '\n';
                }
                else
                {
                    st = n/i;
                }
                if(st == 0) break;
                                        cout << st << " + " << n%i << '\n';
                mn = min(mn, st + n%i);
                if(i == 1e9) break;
            }
            n = mn;
        }
        //        cout << mn;
        ans.push_back(cnt);
        ans.push_back(mn);
    }
        cout << ans[0] << ", " << ans[1] << '\n';
    
    return ans;
}

int main()
{
//    solution(73425);
//    solution(10007);
    solution(12345);
    return 0;
}
