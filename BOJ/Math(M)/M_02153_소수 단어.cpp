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
#include <unordered_map>
#define ll long long

using namespace std;

//https://www.acmicpc.net/problem/2153 소수 단어

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;
    
    int sum = 0;
    for(auto it : s) {
        if('a'<=it && it <='z') {
            it -= ('a' - 1);
        }
        else if('A'<=it && it <='Z') {
            it -= ('A' - 27);
        }
        sum += it;
    }
    
    int prime[2000] = {};
    for(int i=2; i<2000; i++) {
        if(prime[i]) continue;
        for(int j=i+i; j<2000; j+=i) {
            prime[j] = 1;
        }
    }
    
    if(!prime[sum]) cout << "It is a prime word.";
    else cout << "It is not a prime word.";
    
    return 0;
}

