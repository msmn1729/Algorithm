#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

#define ll long long

using namespace std;

long long solution(int n, vector<int> times) {
    ll answer = 0;
    ll st = 1, ed = *max_element(times.begin(), times.end()) * (ll)n;
    
    while(st <= ed) {
        ll avg = (st+ed)>>1;
        ll sum = 0;
        for(int t: times) sum += avg/t;
        if(sum < n) st = avg+1;
        else {
            answer = avg;
            ed = avg-1;
        }
    }
    return answer;
}