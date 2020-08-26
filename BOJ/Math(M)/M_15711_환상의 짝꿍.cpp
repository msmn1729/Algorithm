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

//https://www.acmicpc.net/problem/15711 환상의 짝꿍
//많은 수학적 테크닉이 필요한 어려운 문제
//소수

vector<int> v;
bool primeCheck(long long n)
{
    int i;
    for(i=0; i < v.size(); i++)
    {
        if((long long)v[i]*v[i] > n) return true;
        if(n%v[i] == 0) return false;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int prime[2000001] = {}; //4조의 sqrt
    //에라토스테네스의 체
    for(int i=2; i*i<=2000000; i++)
    {
        if(prime[i]) continue;
        for(int j=i*i; j<=2000000; j+=i) prime[j] = 1;
    }
    for(int i=2; i<=2000000; i++)
    {
        if(!prime[i]) v.push_back(i);
    }
    long long t, a, b;
    cin >> t;
    while(t--)
    {
        cin >> a >> b;
        a += b; //최대 4조
        if(a <= 3) //a가 2, 3이면 불가
        {
            cout << "NO\n";
        }
        else if(a%2 == 0) //골드바흐의 추측
            cout << "YES\n";
        else //합이 홀수인 경우는 둘 중 하나가 짝수인 경우
        {
            //짝수인 소수는 2뿐
            if(primeCheck(a-2)) //둘의 합에서 2를 뺀 것을 소수판별
            {
                cout << "YES\n";
            }
            else cout << "NO\n";
        }
    }
    return 0;
}
