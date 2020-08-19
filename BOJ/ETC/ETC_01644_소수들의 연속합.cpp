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
#include <cstdlib>
#include <cmath>

using namespace std;

//https://www.acmicpc.net/problem/1644 소수의 연속합 골드3
//소수와 투 포인터
//하지만 소수처리만 해줘도 통과됨
//에라토스테네스의 체를 활용시 26배 빨라짐

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, i, j, ans=0;
    
    cin >> n;
    
    vector<int> sieve(n+1), v;
//    fill(v.begin(), v.begin()+n, 0);
    
    for(i=2; i<=n; i++)
    {
        if(sieve[i]) continue;
        v.push_back(i);
        if(i*i > n) continue;
        for(j=i+i; j<=n; j+=i) sieve[j] = 1;
    }
    
//    for(i=2; i<=n; i++)
//        if(sieve[i] == 0)
//            v.push_back(i);
    

//    for(i=2; i<=n; i++)
//    {
//        flag = 1;
//        for(j=2; j*j<=i; j++)
//        {
//            if(i % j == 0)
//            {
//                flag = 0;
//                break;
//            }
//        }
//        if(flag) //소수인 경우
//        {
//            v.push_back(i);
//        }
//    }
    
    //내가 푼 방법
//    for(i=(int)v.size()-1; i>=0; i--)
//    {
//        int tmp = n;
//        if(n >= v[i]) //값보다 작은 소수일 때
//        {
//            for(j=0; i-j>=0;j++)
//            {
//                tmp -= v[i-j];
//                if(tmp == 0)
//                {
//                    ans++;
//                    break;
//                }
//                else if(tmp < 0 ) break;
//            }
//        }
//    }

    //투 포인터방식
    int start=0, end=0, sum=0;

    while(1)
    {
        //부분합이 n보다 큰 경우
        if(sum >= n)
        {
            sum = sum - v[start++];
        }
        else if(end == v.size()) break;
        else //부분합이 n보다 작은 경우
        {
            sum = sum + v[end++];
        }
        if(sum == n) ans++;
    }
    cout << ans;

    return 0;
}
