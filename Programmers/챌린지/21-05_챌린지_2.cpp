#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <climits>
#include <cstring>
#include <iomanip>
#include <bitset>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>

#define ll long long
#define INF 1e9

using namespace std;

ll twoConvertTen(string s) {
    ll ret = 0, mul = 1;
    
    for(int i=(int)s.size()-1; i>=0; i--) {
        mul = 1;
        for(int j=0; j<s.size()-i-1; j++) mul *= 2;
        if(s[i] == '1') ret += mul;
    }
    return ret;
}

vector<ll> solution(vector<ll> numbers) {
    vector<ll> answer;
    
    for(int i=0; i<numbers.size(); i++) {
        ll n = numbers[i];
        if(n%2 == 0) {
            answer.push_back(n+1);
            continue;
        }
        string s = bitset<51>(n).to_string();
        int zero_pos = 0;
        int one_pos = 0;
        
        for(int j=(int)s.size()-1; j>=0; j--) {
            if(s[j] == '0') {
                zero_pos = j;
                break;
            }
        }
        
        for(int j=zero_pos; j<s.size(); j++) {
            if(s[j] == '1') {
                one_pos = j;
                break;
            }
        }
        
        s[zero_pos] = '1';
        s[one_pos] = '0';
        ll tmp = twoConvertTen(s);
        answer.push_back(tmp);
    }
    
    return answer;
}

int main() {
    solution({2, 7});
    
    return 0;
}
