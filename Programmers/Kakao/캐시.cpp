#include <bits/stdc++.h>
using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    vector<string> v;
    
    if(cacheSize == 0) return cities.size() * 5;
    for(string s : cities) {
        for(int i=0; i<s.size(); i++) s[i] = tolower(s[i]);
        auto it = find(v.begin(), v.end(), s);
        // 캐시 미스
        if(it == v.end()) {
            if(v.size() == cacheSize) v.erase(v.begin());
            answer += 5;
        }
        // 캐시 히트
        else {
            v.erase(it);
            answer++;
        }
        v.push_back(s);
    } 
    
    return answer;
}