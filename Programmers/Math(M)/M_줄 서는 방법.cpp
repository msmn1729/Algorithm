#include <cmath>
#include <vector>
#define ll long long

using namespace std;

vector<int> solution(int n, ll k) {
    ll fac = 1;
    for(ll i=1; i<=n-1; i++) fac *= i;
    
    vector<int> v(1), answer;
    for(int i=1; i<=n; i++) v.push_back(i);
    
    ll tmp = n-1;
    while(v.size() > 1) {
        int n = ceil((double)k/fac);
        answer.push_back(v[n]);
        v.erase(v.begin() + n);
        if(k%fac == 0) k = fac;
        else k %= fac;
        if(tmp > 0) {
            fac /= tmp;
            tmp--;
        }
    }
    return answer;
}
