#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    
    // 0. 빠른 풀이
    sort(citations.begin(), citations.end(), greater<>());
    for(int i=0; i<citations.size(); i++) {
        if(citations[i] <= answer) return answer;
        answer++;
    }
    
    // 1. 이진 탐색
    // for(int i=citations.back(); i>=0; i--) {
    //     int high = citations.end() - lower_bound(citations.begin(), citations.end(), i);
    //     int low = citations.size() - high;
    //     if(high >= i && low <= i) return i;
    // }
    
    // 2. prefix sum
    // int ar[10001] = {};
    // for(int c: citations) ar[c]++;
    // int mx = *max_element(citations.begin(), citations.end());
    // for(int i=1; i<=mx; i++) ar[i] += ar[i-1];
    // for(int i=mx; i>=0; i--) {
    //     int high = ar[mx] - ar[i-1];
    //     int low = ar[i];
    //     if(high >= i) return i;
    // }
    
    return answer;
}