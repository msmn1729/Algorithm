#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <map>
#include <sstream>
#include <cmath>
#include <cstring>
#include <stack>
#define ll long long
using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    ll target_sum = 0;
    ll sum = 0;
    vector<int> v;
    v.insert(v.end(), queue1.begin(), queue1.end());
    v.insert(v.end(), queue2.begin(), queue2.end());
    
    for(int i=0; i<v.size(); i++) {
        target_sum += v[i];
    }
    
    for(int i=0; i<queue1.size(); i++) {
        sum += v[i];
    }
    
    if(target_sum % 2) return -1;
    target_sum /= 2;
    
    int st = 0, ed = (int)queue1.size() - 1;
    while(ed < v.size()) {
        if(target_sum == sum) {
            return answer;
        }
        if(target_sum > sum) {
            ed++;
            sum += v[ed];
        }
        else if(target_sum < sum) {
            sum -= v[st];
            st++;
        }
        answer++;
    }
    
    return -1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
//    cout << solution({3, 2, 7, 2}, {4, 6, 5, 1});
    cout << solution({1, 1}, {1, 1});
    
    return 0;
}
